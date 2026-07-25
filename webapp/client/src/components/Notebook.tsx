import Markdown from "react-markdown";
import remarkGfm from "remark-gfm";
import { Prism as SyntaxHighlighter } from "react-syntax-highlighter";
import { oneDark } from "react-syntax-highlighter/dist/esm/styles/prism";

interface RawCell {
  cell_type: string;
  source: string[] | string;
  outputs?: Array<{
    output_type: string;
    text?: string[] | string;
    data?: Record<string, string[] | string>;
  }>;
}

function joinSource(source: string[] | string | undefined): string {
  if (Array.isArray(source)) return source.join("");
  return source ?? "";
}

function renderOutput(cell: RawCell, index: number) {
  if (!cell.outputs?.length) return null;
  return cell.outputs.map((out, oi) => {
    const stream = joinSource(out.text);
    const plain = joinSource(out.data?.["text/plain"]);
    const body = stream || plain;
    if (!body) return null;
    return (
      <pre key={`${index}-${oi}`} className="nb-output">
        {body}
      </pre>
    );
  });
}

export default function Notebook({ content }: { content: string }) {
  let cells: RawCell[] = [];
  try {
    const parsed = JSON.parse(content) as { cells?: RawCell[] };
    cells = parsed.cells ?? [];
  } catch {
    return <p className="viewer-error">Could not parse notebook.</p>;
  }

  return (
    <div className="notebook">
      {cells.map((cell, i) => {
        const source = joinSource(cell.source);
        if (cell.cell_type === "markdown") {
          return (
            <div key={i} className="nb-md prose">
              <Markdown remarkPlugins={[remarkGfm]}>{source}</Markdown>
            </div>
          );
        }
        return (
          <div key={i} className="nb-code">
            <SyntaxHighlighter language="python" style={oneDark} customStyle={{ margin: 0 }}>
              {source}
            </SyntaxHighlighter>
            {renderOutput(cell, i)}
          </div>
        );
      })}
    </div>
  );
}
