cmake_minimum_required(VERSION 3.11.0)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
project(TheGame VERSION 1.0.0)

if(MSVC)
    set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS TRUE)
    set(BUILD_SHARED_LIBS TRUE)
endif()

## PROJECT OUTPUT DIR ##
# Compute a bin/<OS>-<bitness>/<config> path so Debug/Release builds and
# different platforms don't overwrite each other's binaries.
set(OSBitness 32)
if(CMAKE_SIZEOF_VOID_P EQUAL 8)
    set(OSBitness 64)
endif()

set(OutputDir "${CMAKE_SOURCE_DIR}/bin/${CMAKE_SYSTEM_NAME}-${OSBitness}/${CMAKE_BUILD_TYPE}")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${OutputDir}/lib")  # static libs (.a/.lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${OutputDir}")      # shared libs (.so/.dll)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${OutputDir}")      # executables

## LIBRARY LISTING
# Fetch raylib
# FetchContent downloads + configures raylib as a subproject at configure
# time, instead of requiring it to be installed on the system. This runs
# once here at the top level; every target below just links against the
# `raylib` target it produces.
include(FetchContent)
fetchcontent_declare(
    raylib
    GIT_REPOSITORY https://github.com/raysan5/raylib.git
    GIT_TAG 6.0
)
fetchcontent_makeavailable(raylib)

# Descend into src/, which just routes further into src/core and
# src/entities — each of those defines its own library target
# (`core`, `entities`).
add_subdirectory(src)

add_executable(${PROJECT_NAME} main.cpp)

# Only `entities` needs to be named here: it links `core` PUBLIC, and
# `core` links raylib PUBLIC, so both are pulled in transitively. Anything
# a header exposes has to be PUBLIC somewhere in that chain for this to
# work — see src/core/CMakeLists.txt for why.
target_link_libraries(${PROJECT_NAME} PRIVATE entities)
