# Search Algorithms Implementation

This project provides an implementation of several fundamental search algorithms in C++. The algorithms included are:

- **Dijkstra's Algorithm**: Finds the shortest paths from a single source vertex to all other vertices in a weighted graph with non-negative edge weights.
- **Bellman-Ford Algorithm**: Computes the shortest paths from a single source vertex to all other vertices in a graph that may contain negative edge weights.
- **A-star Algorithm**: Finds the shortest path between nodes using heuristics to improve efficiency in pathfinding.

## Features

- **CMake Support**: The project uses CMake for build configuration and management.
- **Direct Compilation**: You can also compile the project directly using the provided `g++` command.

## Compilation

To compile the project, you have two options:

**1. Using CMake:**

   ```sh
   # Check if the 'build' directory exists
   if (Test-Path -Path "build") {
       Write-Output "Removing existing 'build' directory..."
       Remove-Item -Path "build" -Recurse -Force
   }
   
   # Create the 'build' directory
   New-Item -Path "build" -ItemType Directory
   
   # Change to the 'build' directory
   Set-Location -Path "build"
   
   # Run cmake and make commands
   cmake -G "MinGW Makefiles" ..
   mingw32-make
   ```

**2. Direct Compilation:**
   ```sh
   g++ -std=c++23 -o main.exe main.cpp ./search/node.cpp ./search/graph.cpp -I search
   ```
    
## Usage
After compilation, you can run the main.exe to execute the search algorithms. Ensure that all necessary source files are in the appropriate directories.

## Contributing
Feel free to contribute to this project by submitting issues or pull requests. Your contributions are welcome!
