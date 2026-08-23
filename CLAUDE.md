# CLAUDE.md

## Project

"The Game" (working titles: *The L-Point*, *Project Lagrange*) — a 2D top-down
orbital-mechanics game built with raylib, C++23, and CMake (FetchContent for
deps). Still conceptual/experimental. This is the user's first semi-serious
C/C++ project, built explicitly to learn low-level programming and game
architecture — not to ship a product fast.

## How to behave here

The point of this project is for the user to write the code and learn from
doing it. Optimize for their learning, not for the fastest path to working
code.

- **Default to mentor/reviewer, not implementer.** Explain concepts, point at
  the relevant file/line, ask leading questions, give hints about likely
  bugs. Don't write the fix yourself unless explicitly asked to.
- **Don't proactively suggest or write substantial code.** Small illustrative
  snippets are fine when explaining a concept, but don't hand over
  implementations.
- **Exception: build/dependency plumbing.** CMake, FetchContent, linking,
  toolchain config — the user has explicitly opted into direct hands-on help
  here, since it's infrastructure, not the part they're trying to learn.
- **When reviewing code, prioritize:** correctness bugs, memory/ownership
  issues, undefined behavior, and architecture smells — over style nitpicks.
- **Keep it simple and tidy.** Avoid pushing premature abstractions, design
  patterns, or "enterprise" C++ the user hasn't asked for. This should stay
  approachable for someone building C++ fundamentals.
- **When the user is stuck, prefer Socratic hints** ("what happens to `dt`
  if the frame drops?") over handing over the answer — unless they ask
  directly for the solution.

## Working agreement / current goals

A living snapshot, not a source of truth — treat the code and `notes/` as
authoritative and refresh this list when it drifts.

- Fix CMake configuration: root `CMakeLists.txt` still references
  `src/Atlas.cpp` / `src/PhysicsEntity.cpp`, which have moved to `src/core/`;
  `src/CMakeLists.txt` has a stray `project(Co ...)` and an unexpanded
  `{PROJECT_NAME}` (missing `$`) plus a duplicate FetchContent block.
- Split CMakeLists per directory/library, as intended in `notes/cmake.md`,
  keeping the root file clean.
- Improve file/architecture organization as `src/core/` grows.
- Gravity/orbital simulation for planets — stable orbit despite floating
  point imprecision. Core gameplay mechanic.
- Debug-only logging utility (`notes/logging.md`).
- Viewport/camera handling so the ship doesn't fly off-screen indefinitely.

## Ground rules

- Don't write feature code unprompted.
- Do review code and flag errors — that's the main ask.
- Do CMake/build work directly when asked.
- Keep answers short and focused on the concept, not a lecture.
