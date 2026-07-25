import { useState } from "react";
import type { TreeNode } from "../api.js";

const KIND_ICON: Record<string, string> = {
  markdown: "📓",
  notebook: "🔬",
  pdf: "📄",
  code: "⚙️",
  text: "📃",
  binary: "▪",
};

interface Props {
  nodes: TreeNode[];
  selected: string | null;
  onSelect: (node: TreeNode) => void;
}

function Entry({ node, selected, onSelect, depth }: {
  node: TreeNode;
  selected: string | null;
  onSelect: (node: TreeNode) => void;
  depth: number;
}) {
  const [open, setOpen] = useState(depth < 1);

  if (node.type === "dir") {
    return (
      <li>
        <button
          className="tree-row tree-dir"
          style={{ paddingLeft: depth * 14 + 8 }}
          onClick={() => setOpen((v) => !v)}
        >
          <span className="tree-caret">{open ? "▾" : "▸"}</span>
          <span className="tree-label">{node.name}</span>
        </button>
        {open && node.children && (
          <ul className="tree-list">
            {node.children.map((child) => (
              <Entry
                key={child.path}
                node={child}
                selected={selected}
                onSelect={onSelect}
                depth={depth + 1}
              />
            ))}
          </ul>
        )}
      </li>
    );
  }

  const active = selected === node.path;
  return (
    <li>
      <button
        className={`tree-row tree-file${active ? " is-active" : ""}`}
        style={{ paddingLeft: depth * 14 + 8 }}
        onClick={() => onSelect(node)}
      >
        <span className="tree-icon">{KIND_ICON[node.kind ?? "text"]}</span>
        <span className="tree-label">{node.name}</span>
        {node.language && <span className="tree-lang">{node.language}</span>}
      </button>
    </li>
  );
}

export default function Tree({ nodes, selected, onSelect }: Props) {
  return (
    <ul className="tree-list tree-root">
      {nodes.map((node) => (
        <Entry
          key={node.path}
          node={node}
          selected={selected}
          onSelect={onSelect}
          depth={0}
        />
      ))}
    </ul>
  );
}
