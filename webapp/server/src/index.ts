import cors from "cors";
import express from "express";
import { PORT } from "./config.js";
import { readTextFile, resolvePdf } from "./files.js";
import { languageFor } from "./languages.js";
import { PathError, resolveContentPath } from "./paths.js";
import { runExperiment } from "./runner.js";
import { buildTree } from "./tree.js";

const app = express();
app.use(cors());
app.use(express.json());

function requirePath(value: unknown): string {
  if (typeof value !== "string" || value.length === 0) {
    throw new PathError("Query parameter 'path' is required");
  }
  return value;
}

app.get("/api/tree", async (_req, res, next) => {
  try {
    res.json({ roots: await buildTree() });
  } catch (err) {
    next(err);
  }
});

app.get("/api/file", async (req, res, next) => {
  try {
    const payload = await readTextFile(requirePath(req.query.path));
    res.json(payload);
  } catch (err) {
    next(err);
  }
});

app.get("/api/pdf", async (req, res, next) => {
  try {
    const absolute = resolvePdf(requirePath(req.query.path));
    res.type("application/pdf");
    res.sendFile(absolute);
  } catch (err) {
    next(err);
  }
});

app.post("/api/execute", async (req, res, next) => {
  try {
    const relative = requirePath((req.body as { path?: unknown }).path);
    const absolute = resolveContentPath(relative);
    const language = languageFor(absolute);
    if (!language) {
      res.status(400).json({ error: "File is not an executable experiment" });
      return;
    }
    const result = await runExperiment(absolute, language);
    res.json({ language: language.id, label: language.label, ...result });
  } catch (err) {
    next(err);
  }
});

app.use(
  (
    err: unknown,
    _req: express.Request,
    res: express.Response,
    _next: express.NextFunction,
  ) => {
    const status = err instanceof PathError ? 400 : 500;
    const message = err instanceof Error ? err.message : "Unexpected error";
    res.status(status).json({ error: message });
  },
);

app.listen(PORT, () => {
  console.log(`Academie API listening on http://localhost:${PORT}`);
});
