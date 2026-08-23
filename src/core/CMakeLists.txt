# `core` = engine-ish building blocks that don't know what a spaceship or a
# planet is (physics base class, texture/atlas loading). Only list .cpp
# files here — headers don't need to be listed, CMake discovers them via
# #include when compiling these sources.
add_library(core
    Atlas.cpp
    PhysicsEntity.cpp
)

# PUBLIC: this directory is added to the include path both when compiling
# `core` itself AND for any target that later links against `core`. That's
# what lets main.cpp say `#include <Atlas.hpp>` and entities/Starship.cpp
# say `#include "PhysicsEntity.hpp"` without knowing this is core/ on disk.
target_include_directories(core PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# PUBLIC, not PRIVATE: Atlas.hpp and PhysicsEntity.hpp use raylib types
# (Vector2, Texture2D, Rectangle) directly in their class declarations.
# That means raylib's own headers are part of core's PUBLIC interface —
# anything that includes our headers transitively needs raylib's headers
# too. PUBLIC propagates that requirement to whoever links `core`.
target_link_libraries(core PUBLIC raylib)

# PRIVATE: only Atlas.cpp actually reads PROJECT_ROOT (to locate the
# spritesheet asset at runtime). No public header depends on it, so it
# has no reason to leak to consumers of this library.
target_compile_definitions(core PRIVATE PROJECT_ROOT="${CMAKE_SOURCE_DIR}")
