# L'Academie — Notes & Experiments

A small web app to browse the class notes in this repository and run the code in
Experiments/ straight from the browser. Open a C, C++ or Python file, press
Execute, and the server compiles and runs it and streams the results back.

## Stack

- Server: Node + Express 5 + TypeScript (run with tsx). Walks the content
  directories, serves file contents, and compiles/runs experiments in a
  sandboxed temp directory with a timeout and an output cap.
- Client: React 19 + Vite + TypeScript. Tree browser, Markdown and Jupyter
  notebook rendering, syntax-highlighted code, and an execute panel.

## Requirements

The server shells out to the toolchains already installed on the machine.

- Node 20 or newer
- gcc (for C)
- g++ (for C++)
- python3 (for Python)

## Install

```
cd webapp
npm install
```

This installs both workspaces (server and client). If npm blocks the esbuild
install script, approve it once:

```
npm install-scripts approve esbuild && npm rebuild esbuild
```

## Run (development)

```
cd webapp
npm run dev
```

- Client on http://localhost:5173
- Server on http://localhost:4000 (the client proxies /api to it)

Open http://localhost:5173, pick a note or experiment on the left, and for code
files press Execute.

## Build (client production bundle)

```
cd webapp
npm run build          # outputs client/dist
```

## What gets exposed

Only the College, Courses and Experiments directories at the repository root are
readable through the API. Requests are resolved against that root and anything
resolving outside it is rejected.

## API

- GET /api/tree — the full content tree
- GET /api/file?path=... — text content for notes, code, notebooks
- GET /api/pdf?path=... — a PDF stream
- POST /api/execute { path } — compile and run one experiment, returns
  { stdout, stderr, exitCode, timedOut, durationMs, compileError? }

## Execution model

Each run happens in a fresh temp directory with the source file's own directory
as the working directory, so experiments that read a sibling data file (for
example the File Management exercises) find it. Runs are killed after 10 seconds
and captured output is capped at 256 KB.

Executable languages are C (.c), C++ (.cpp/.cc/.cxx) and Python (.py). Notebooks
and PDFs are shown but not executed.

## Security note

The execute endpoint compiles and runs arbitrary source from the repository with
the privileges of the server process. It is meant for local use on your own
notes. Do not expose this server to an untrusted network.

## Layout

```
webapp/
  server/   Express API, file tree, code runner
  client/   React browser and viewers
```
