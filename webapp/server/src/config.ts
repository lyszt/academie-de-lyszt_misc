import path from "node:path";
import { fileURLToPath } from "node:url";

const here = path.dirname(fileURLToPath(import.meta.url));

/** Repository root that holds the notes and Experiments directories. */
export const REPO_ROOT = path.resolve(here, "..", "..", "..");

export const PORT = Number(process.env.PORT ?? 4000);

/** Top-level directories exposed to the browser. */
export const CONTENT_DIRS = ["College", "Courses", "Experiments"];

/** Directory names skipped while walking the tree. */
export const IGNORED_DIRS = new Set([
  ".git",
  ".idea",
  ".vscode",
  "node_modules",
  "__pycache__",
]);

/** Wall-clock limit for a single experiment run. */
export const RUN_TIMEOUT_MS = 10_000;

/** Cap captured output so a runaway program cannot exhaust memory. */
export const MAX_OUTPUT_BYTES = 256 * 1024;
