# This file intentionally builds nothing itself. Each subdirectory is a
# library in its own right (per notes/cmake.md) with its own CMakeLists.txt
# that knows its own sources and dependencies. Add a new line here whenever
# a new top-level src/ folder needs to become a library.
add_subdirectory(core)
add_subdirectory(entities)
