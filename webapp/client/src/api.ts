export interface TreeNode {
  name: string;
  path: string;
  type: "dir" | "file";
  children?: TreeNode[];
  kind?: "markdown" | "notebook" | "pdf" | "code" | "text" | "binary";
  language?: string;
}

export interface FilePayload {
  path: string;
  name: string;
  kind: "markdown" | "notebook" | "code" | "text";
  language?: string;
  content: string;
}

export interface RunResult {
  language: string;
  label: string;
  stdout: string;
  stderr: string;
  exitCode: number | null;
  timedOut: boolean;
  durationMs: number;
  compileError?: string;
}

async function json<T>(res: Response): Promise<T> {
  if (!res.ok) {
    const body = (await res.json().catch(() => ({}))) as { error?: string };
    throw new Error(body.error ?? `Request failed (${res.status})`);
  }
  return res.json() as Promise<T>;
}

export function fetchTree(): Promise<{ roots: TreeNode[] }> {
  return fetch("/api/tree").then((r) => json(r));
}

export function fetchFile(path: string): Promise<FilePayload> {
  return fetch(`/api/file?path=${encodeURIComponent(path)}`).then((r) => json(r));
}

export function executeFile(path: string): Promise<RunResult> {
  return fetch("/api/execute", {
    method: "POST",
    headers: { "Content-Type": "application/json" },
    body: JSON.stringify({ path }),
  }).then((r) => json(r));
}

export function pdfUrl(path: string): string {
  return `/api/pdf?path=${encodeURIComponent(path)}`;
}
