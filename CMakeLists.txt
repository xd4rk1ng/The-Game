cmake_minimum_required(VERSION 3.11.0)
project(TheGame VERSION 1.0.0)

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
FetchContent_Declare(
    raylib
    GIT_REPOSITORY https://github.com/raysan5/raylib.git
    GIT_TAG 6.0
    )
FetchContent_MakeAvailable(raylib)

# Compile libraries
# add_libary(name STATIC filename.cpp)
# add_libary(name SHARED filename.cpp)
# add_libary(name filename.cpp)

add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} PRIVATE raylib)
