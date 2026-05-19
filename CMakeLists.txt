cmake_minimum_required(VERSION 3.11.0)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
project(TheGame VERSION 1.0.0)

if(MSVC)
    set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS TRUE)
    set(BUILD_SHARED_LIBS TRUE)
endif()

## PROJECT OUTPUT DIR ##
set(OSBitness 32)
if(CMAKE_SIZEOF_VOID_P EQUAL 8)
    set(OSBitness 64)
endif()

set(OutputDir "${CMAKE_SOURCE_DIR}/bin/${CMAKE_SYSTEM_NAME}-${OSBitness}/${CMAKE_BUILD_TYPE}")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${OutputDir}/lib")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${OutputDir}")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${OutputDir}")

## LIBRARY LISTING
# Fetch raylib
include(FetchContent)
fetchcontent_declare(
    raylib
    GIT_REPOSITORY https://github.com/raysan5/raylib.git
    GIT_TAG 6.0
)
fetchcontent_makeavailable(raylib)

# Compile libraries
set(SourceFiles
    src/Atlas.cpp
)
add_library(atlas ${SourceFiles})

include_directories(src)

add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(atlas PRIVATE raylib)
target_compile_definitions(atlas PRIVATE PROJECT_ROOT="${CMAKE_SOURCE_DIR}")
target_link_libraries(${PROJECT_NAME} PRIVATE raylib atlas)
