cmake_minimum_required(VERSION 3.10)  # Specify CMake version
project(Searching_Algorithms VERSION 1.1 LANGUAGES CXX)  # Project name and version

set(CMAKE_CXX_STANDARD 23)  # Use C++23 (equivalent to -std=c++2b)

# Include directories
include_directories(
    ${PROJECT_SOURCE_DIR}/search
)

# Add executable
add_executable(main
    main.cpp
    search/graph.cpp
    search/node.cpp
)

