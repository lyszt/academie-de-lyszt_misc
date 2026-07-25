import { spawn } from "node:child_process";
import fs from "node:fs/promises";
import os from "node:os";
import path from "node:path";
import { MAX_OUTPUT_BYTES, RUN_TIMEOUT_MS } from "./config.js";
import { type Language } from "./languages.js";

export interface RunResult {
  stdout: string;
  stderr: string;
  exitCode: number | null;
  timedOut: boolean;
  durationMs: number;
  /** Compiler diagnostics, present for compiled languages that failed to build. */
  compileError?: string;
}

interface Command {
  file: string;
  args: string[];
}

/** Captures a child process with a wall-clock timeout and an output cap. */
function exec(
  command: Command,
  cwd: string,
): Promise<{ stdout: string; stderr: string; code: number | null; timedOut: boolean }> {
  return new Promise((resolve) => {
    const child = spawn(command.file, command.args, {
      cwd,
      stdio: ["ignore", "pipe", "pipe"],
    });

    let stdout = "";
    let stderr = "";
    let timedOut = false;

    const capture = (chunk: Buffer, sink: "out" | "err") => {
      const text = chunk.toString("utf8");
      if (sink === "out") {
        if (stdout.length < MAX_OUTPUT_BYTES) stdout += text;
      } else if (stderr.length < MAX_OUTPUT_BYTES) {
        stderr += text;
      }
    };

    child.stdout.on("data", (c) => capture(c, "out"));
    child.stderr.on("data", (c) => capture(c, "err"));

    const timer = setTimeout(() => {
      timedOut = true;
      child.kill("SIGKILL");
    }, RUN_TIMEOUT_MS);

    child.on("error", (err) => {
      clearTimeout(timer);
      resolve({ stdout, stderr: stderr + String(err.message), code: null, timedOut });
    });

    child.on("close", (code) => {
      clearTimeout(timer);
      resolve({ stdout, stderr, code, timedOut });
    });
  });
}

function truncationNote(text: string): string {
  return text.length >= MAX_OUTPUT_BYTES ? "\n[output truncated]" : "";
}

/**
 * Compiles when needed and runs a single source file in an isolated temp dir.
 * Receives the source path plus its language and returns the captured result.
 */
export async function runExperiment(
  sourceAbs: string,
  language: Language,
): Promise<RunResult> {
  const workDir = await fs.mkdtemp(path.join(os.tmpdir(), "academie-run-"));
  const started = performance.now();
  // Run from the source directory so experiments that read sibling data files work.
  const runCwd = path.dirname(sourceAbs);

  try {
    if (language.id === "python") {
      const run = await exec({ file: "python3", args: [sourceAbs] }, runCwd);
      return {
        stdout: run.stdout + truncationNote(run.stdout),
        stderr: run.stderr + truncationNote(run.stderr),
        exitCode: run.code,
        timedOut: run.timedOut,
        durationMs: Math.round(performance.now() - started),
      };
    }

    const compiler = language.id === "c" ? "gcc" : "g++";
    const std = language.id === "c" ? "-std=c11" : "-std=c++20";
    const binary = path.join(workDir, "program");

    const build = await exec(
      { file: compiler, args: [std, "-O0", "-o", binary, sourceAbs] },
      workDir,
    );

    if (build.code !== 0) {
      return {
        stdout: "",
        stderr: "",
        exitCode: build.code,
        timedOut: build.timedOut,
        durationMs: Math.round(performance.now() - started),
        compileError: build.stderr || build.stdout || "Compilation failed",
      };
    }

    const run = await exec({ file: binary, args: [] }, runCwd);
    return {
      stdout: run.stdout + truncationNote(run.stdout),
      stderr: run.stderr + truncationNote(run.stderr),
      exitCode: run.code,
      timedOut: run.timedOut,
      durationMs: Math.round(performance.now() - started),
    };
  } finally {
    await fs.rm(workDir, { recursive: true, force: true });
  }
}
