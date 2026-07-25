import Markdown from "react-markdown";
import remarkGfm from "remark-gfm";
import { Prism as SyntaxHighlighter } from "react-syntax-highlighter";
import { oneDark } from "react-syntax-highlighter/dist/esm/styles/prism";
import type { FilePayload, TreeNode } from "../api.js";
import { pdfUrl } from "../api.js";
import ExecutePanel from "./ExecutePanel.js";
import Notebook from "./Notebook.js";

interface Props {
  node: TreeNode;
  file: FilePayload | null;
  loading: boolean;
  error: string | null;
}

function CodeView({ file }: { file: FilePayload }) {
  return (
    <>
      {file.language && <ExecutePanel path={file.path} label={file.language} />}
      <SyntaxHighlighter
        language={file.language ?? "text"}
        style={oneDark}
        showLineNumbers
        customStyle={{ margin: 0, borderRadius: 8 }}
      >
        {file.content}
      </SyntaxHighlighter>
    </>
  );
}

export default function Viewer({ node, file, loading, error }: Props) {
  if (node.kind === "pdf") {
    return (
      <div className="viewer">
        <header className="viewer-head">
          <h2>{node.name}</h2>
          <span className="viewer-path">{node.path}</span>
        </header>
        <iframe className="pdf-frame" src={pdfUrl(node.path)} title={node.name} />
      </div>
    );
  }

  return (
    <div className="viewer">
      <header className="viewer-head">
        <h2>{node.name}</h2>
        <span className="viewer-path">{node.path}</span>
      </header>

      {loading && <p className="viewer-status">Loading…</p>}
      {error && <p className="viewer-error">{error}</p>}

      {file && !loading && (
        <div className="viewer-body">
          {file.kind === "markdown" && (
            <article className="prose">
              <Markdown remarkPlugins={[remarkGfm]}>{file.content}</Markdown>
            </article>
          )}
          {file.kind === "notebook" && <Notebook content={file.content} />}
          {file.kind === "code" && <CodeView file={file} />}
          {file.kind === "text" && <pre className="text-view">{file.content}</pre>}
        </div>
      )}
    </div>
  );
}
