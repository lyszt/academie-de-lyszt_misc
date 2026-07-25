import path from "node:path";
import { CONTENT_DIRS, REPO_ROOT } from "./config.js";

/** Thrown when a requested path escapes the exposed content directories. */
export class PathError extends Error {}

/**
 * Resolves a client-supplied relative path to an absolute path inside REPO_ROOT.
 * Receives a POSIX-style relative path and returns the validated absolute path.
 */
export function resolveContentPath(relative: string): string {
  if (typeof relative !== "string" || relative.length === 0) {
    throw new PathError("Path is required");
  }

  const normalized = path.normalize(relative).replace(/^(\.\.[/\\])+/, "");
  const absolute = path.resolve(REPO_ROOT, normalized);
  const rootWithSep = REPO_ROOT + path.sep;

  if (absolute !== REPO_ROOT && !absolute.startsWith(rootWithSep)) {
    throw new PathError("Path is outside the content root");
  }

  const top = path.relative(REPO_ROOT, absolute).split(path.sep)[0];
  if (!CONTENT_DIRS.includes(top ?? "")) {
    throw new PathError("Path is not in an exposed directory");
  }

  return absolute;
}

/** Converts an absolute path back to a POSIX relative path from REPO_ROOT. */
export function toRelative(absolute: string): string {
  return path.relative(REPO_ROOT, absolute).split(path.sep).join("/");
}
