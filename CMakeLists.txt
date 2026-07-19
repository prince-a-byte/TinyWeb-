cmake_minimum_required(VERSION 3.16)

project(TinyWeb
    VERSION 0.2.0
    DESCRIPTION "A lightweight HTTP web framework built from scratch in Modern C++"
    LANGUAGES CXX
)

# Use C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Header files
include_directories(include)

# Source files
set(SOURCES
    src/main.cpp
    src/server.cpp
    src/router.cpp
    src/request.cpp
    src/response.cpp
)

# Create executable
add_executable(TinyWeb ${SOURCES})

# Compiler warnings
target_compile_options(TinyWeb PRIVATE
    -Wall
    -Wextra
    -Wpedantic
)
