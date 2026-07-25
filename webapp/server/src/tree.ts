import fs from "node:fs/promises";
import path from "node:path";
import { CONTENT_DIRS, IGNORED_DIRS, REPO_ROOT } from "./config.js";
import { languageFor } from "./languages.js";
import { toRelative } from "./paths.js";

export interface TreeNode {
  name: string;
  path: string;
  type: "dir" | "file";
  children?: TreeNode[];
  /** Kind of file the client should render for a leaf node. */
  kind?: "markdown" | "notebook" | "pdf" | "code" | "text" | "binary";
  /** Runnable language id, present only for executable code files. */
  language?: string;
}

const VIEWABLE_EXTS = new Set([
  ".md",
  ".markdown",
  ".ipynb",
  ".pdf",
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

function kindFor(filePath: string): TreeNode["kind"] {
  const ext = path.extname(filePath).toLowerCase();
  if (ext === ".md" || ext === ".markdown") return "markdown";
  if (ext === ".ipynb") return "notebook";
  if (ext === ".pdf") return "pdf";
  if (languageFor(filePath)) return "code";
  if (VIEWABLE_EXTS.has(ext)) return "text";
  return "binary";
}

async function walk(absolute: string): Promise<TreeNode[]> {
  const entries = await fs.readdir(absolute, { withFileTypes: true });
  const nodes: TreeNode[] = [];

  for (const entry of entries) {
    if (entry.name.startsWith(".") && entry.isDirectory()) continue;
    if (IGNORED_DIRS.has(entry.name)) continue;

    const childAbs = path.join(absolute, entry.name);

    if (entry.isDirectory()) {
      const children = await walk(childAbs);
      if (children.length > 0) {
        nodes.push({
          name: entry.name,
          path: toRelative(childAbs),
          type: "dir",
          children,
        });
      }
    } else if (entry.isFile()) {
      const ext = path.extname(entry.name).toLowerCase();
      if (!VIEWABLE_EXTS.has(ext)) continue;
      const language = languageFor(childAbs);
      nodes.push({
        name: entry.name,
        path: toRelative(childAbs),
        type: "file",
        kind: kindFor(childAbs),
        ...(language ? { language: language.id } : {}),
      });
    }
  }

  nodes.sort((a, b) => {
    if (a.type !== b.type) return a.type === "dir" ? -1 : 1;
    return a.name.localeCompare(b.name);
  });
  return nodes;
}

/** Builds the full content tree for every exposed top-level directory. */
export async function buildTree(): Promise<TreeNode[]> {
  const roots: TreeNode[] = [];
  for (const dir of CONTENT_DIRS) {
    const absolute = path.join(REPO_ROOT, dir);
    try {
      const children = await walk(absolute);
      roots.push({ name: dir, path: dir, type: "dir", children });
    } catch {
      continue;
    }
  }
  return roots;
}
