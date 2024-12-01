# Search Algorithms Implementation

This project provides an implementation of several fundamental search algorithms in C++. The algorithms included are:

- **Dijkstra's Algorithm**: Finds the shortest paths from a single source vertex to all other vertices in a weighted graph with non-negative edge weights.
- **Bellman-Ford Algorithm**: Computes the shortest paths from a single source vertex to all other vertices in a graph that may contain negative edge weights.
- **A-star Algorithm**: Finds the shortest path between nodes using heuristics to improve efficiency in pathfinding.

## Project Description

This repository contains code that is designed to be easily integrated into other projects. The primary component is the graph-related functionality, which can be seamlessly added to your own codebase.

## Project Structure
```
SEARCHING-ALGORITHMS/
├── example/
│   └── main.cpp           # Example program demonstrating searching algorithms
├── include/
│   ├── graph.h            # Header file for the graph implementation
│   └── node.h             # Header file for the node implementation
├── src/
│   ├── graph.cpp          # Implementation of the graph
│   └── node.cpp           # Implementation of the node
├── CMakeLists.txt         # CMake build configuration
└── run.ps1                # PowerShell script to automate the build and execution
```

### Example

Refer to the `main.cpp` file in this repository for a practical example of how to use the code.

## Features

- **CMake Support**: The project uses CMake for build configuration and management.
- **Direct Compilation**: You can also compile the project directly using the provided `g++` command.
- **Designed as Library**: The project is structured to function as a reusable library.
    
## Usage
After compilation, you can run the main.exe to execute the search algorithms. Ensure that all necessary source files are in the appropriate directories.

## Contributing
Feel free to contribute to this project by submitting issues or pull requests. Your contributions are welcome!
