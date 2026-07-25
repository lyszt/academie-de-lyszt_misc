import { useEffect, useState } from "react";
import { fetchFile, fetchTree, type FilePayload, type TreeNode } from "./api.js";
import Tree from "./components/Tree.js";
import Viewer from "./components/Viewer.js";

export default function App() {
  const [roots, setRoots] = useState<TreeNode[]>([]);
  const [treeError, setTreeError] = useState<string | null>(null);
  const [selected, setSelected] = useState<TreeNode | null>(null);
  const [file, setFile] = useState<FilePayload | null>(null);
  const [loading, setLoading] = useState(false);
  const [fileError, setFileError] = useState<string | null>(null);

  useEffect(() => {
    fetchTree()
      .then((res) => setRoots(res.roots))
      .catch((err) => setTreeError(err instanceof Error ? err.message : "Failed to load tree"));
  }, []);

  function open(node: TreeNode) {
    setSelected(node);
    setFile(null);
    setFileError(null);
    if (node.kind === "pdf") return;

    setLoading(true);
    fetchFile(node.path)
      .then(setFile)
      .catch((err) => setFileError(err instanceof Error ? err.message : "Failed to load file"))
      .finally(() => setLoading(false));
  }

  return (
    <div className="app">
      <aside className="sidebar">
        <div className="brand">
          <span className="brand-mark">L'Academie</span>
          <span className="brand-sub">Notes &amp; Experiments</span>
        </div>
        {treeError && <p className="viewer-error">{treeError}</p>}
        <Tree nodes={roots} selected={selected?.path ?? null} onSelect={open} />
      </aside>

      <main className="content">
        {selected ? (
          <Viewer node={selected} file={file} loading={loading} error={fileError} />
        ) : (
          <div className="empty-state">
            <h1>Select a note or experiment</h1>
            <p>
              Browse notes on the left. Open a C, C++ or Python experiment and press
              Execute to compile and run it, then read the results here.
            </p>
          </div>
        )}
      </main>
    </div>
  );
}
