import path from "node:path";

export type LanguageId = "c" | "cpp" | "python";

export interface Language {
  id: LanguageId;
  label: string;
  /** Monaco/highlight.js grammar name for the viewer. */
  syntax: string;
}

const BY_EXTENSION: Record<string, Language> = {
  ".c": { id: "c", label: "C", syntax: "c" },
  ".cpp": { id: "cpp", label: "C++", syntax: "cpp" },
  ".cc": { id: "cpp", label: "C++", syntax: "cpp" },
  ".cxx": { id: "cpp", label: "C++", syntax: "cpp" },
  ".py": { id: "python", label: "Python", syntax: "python" },
};

/** Returns the runnable language for a file, or null when it is not executable. */
export function languageFor(filePath: string): Language | null {
  return BY_EXTENSION[path.extname(filePath).toLowerCase()] ?? null;
}
