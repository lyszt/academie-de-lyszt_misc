import fs from "node:fs/promises";
import path from "node:path";
import { languageFor } from "./languages.js";
import { resolveContentPath, toRelative } from "./paths.js";

export interface FilePayload {
  path: string;
  name: string;
  kind: "markdown" | "notebook" | "code" | "text";
  language?: string;
  content: string;
}

const TEXT_EXTS = new Set([
  ".md",
  ".markdown",
  ".ipynb",
  ".c",
  ".cpp",
  ".cc",
  ".cxx",
  ".h",
  ".hpp",
  ".py",
  ".txt",
  ".json",
  ".csv",
  ".tex",
  ".css",
]);

function kindOf(filePath: string): FilePayload["kind"] {
  const ext = path.extname(filePath).toLowerCase();
  if (ext === ".md" || ext === ".markdown") return "markdown";
  if (ext === ".ipynb") return "notebook";
  if (languageFor(filePath)) return "code";
  return "text";
}

/** Reads a text-based content file and returns its payload for the viewer. */
export async function readTextFile(relative: string): Promise<FilePayload> {
  const absolute = resolveContentPath(relative);
  const ext = path.extname(absolute).toLowerCase();
  if (!TEXT_EXTS.has(ext)) {
    throw new Error("File type is not viewable as text");
  }

  const content = await fs.readFile(absolute, "utf8");
  const language = languageFor(absolute);

  return {
    path: toRelative(absolute),
    name: path.basename(absolute),
    kind: kindOf(absolute),
    ...(language ? { language: language.id } : {}),
    content,
  };
}

/** Resolves a PDF path for streaming, rejecting non-PDF requests. */
export function resolvePdf(relative: string): string {
  const absolute = resolveContentPath(relative);
  if (path.extname(absolute).toLowerCase() !== ".pdf") {
    throw new Error("Not a PDF file");
  }
  return absolute;
}
