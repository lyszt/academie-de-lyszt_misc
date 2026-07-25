import { useState } from "react";
import { executeFile, type RunResult } from "../api.js";

function statusLabel(result: RunResult): { text: string; tone: string } {
  if (result.compileError) return { text: "Compilation failed", tone: "err" };
  if (result.timedOut) return { text: "Timed out", tone: "err" };
  if (result.exitCode === 0) return { text: "Success", tone: "ok" };
  return { text: `Exited with code ${result.exitCode}`, tone: "warn" };
}

export default function ExecutePanel({ path, label }: { path: string; label: string }) {
  const [running, setRunning] = useState(false);
  const [result, setResult] = useState<RunResult | null>(null);
  const [error, setError] = useState<string | null>(null);

  async function run() {
    setRunning(true);
    setError(null);
    setResult(null);
    try {
      setResult(await executeFile(path));
    } catch (err) {
      setError(err instanceof Error ? err.message : "Execution failed");
    } finally {
      setRunning(false);
    }
  }

  const status = result ? statusLabel(result) : null;

  return (
    <div className="exec">
      <div className="exec-bar">
        <button className="exec-run" onClick={run} disabled={running}>
          {running ? "Running…" : `▶ Execute ${label}`}
        </button>
        {result && (
          <span className="exec-meta">{result.durationMs} ms</span>
        )}
        {status && <span className={`exec-status exec-${status.tone}`}>{status.text}</span>}
      </div>

      {error && <pre className="exec-out exec-stderr">{error}</pre>}

      {result?.compileError && (
        <section>
          <h4 className="exec-heading">Compiler output</h4>
          <pre className="exec-out exec-stderr">{result.compileError}</pre>
        </section>
      )}

      {result && !result.compileError && (
        <>
          {result.stdout && (
            <section>
              <h4 className="exec-heading">Output</h4>
              <pre className="exec-out">{result.stdout}</pre>
            </section>
          )}
          {result.stderr && (
            <section>
              <h4 className="exec-heading">Errors</h4>
              <pre className="exec-out exec-stderr">{result.stderr}</pre>
            </section>
          )}
          {!result.stdout && !result.stderr && (
            <p className="exec-empty">Program produced no output.</p>
          )}
        </>
      )}
    </div>
  );
}
