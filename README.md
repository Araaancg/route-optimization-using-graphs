# Route Optimization Using Graphs in C++

This repository corresponds to a final project for MSMK University Unit 20 - Advanced Programming and Design Principles in the Applied Computing and AI Professional Degree. The final grade was 'Distinction'.

## Overview

This project implements two fundamental graph traversal algorithms: **Depth-First Search (DFS)** and **Breadth-First Search (BFS)**, using **C++**. Given a graph, the goal is to simulate the exploration of its nodes through these two algorithms and determine which will give us the faster option.

The graph is represented as a collection of nodes and edges, and the main objective of this project is to implement the functions that imitate the **DFS** and **BFS** algorithms to explore the graph. The graph presented is one that connects spanish cities between each other and also gives us the distance. 
- Madrid – Ciudad Real = 100km
- Ciudad Real – Salamanca = 100km
- Madrid – Toledo = 80km
- Madrid – Salamanca = 190km
- Toledo – Albacete = 150km
- Toledo – Jaén = 180km
- Toledo – Ciudad Real = 50km
- Salamanca -Guadalajara = 100km
- Salamanca - Cáceres= 150km
- Cáceres - Jaén= 150km
- Salamanca - Jaén= 100km

Additionally, the project serves as an opportunity to work with **CMake**, explore more advanced **C++** features such as **pointers and references**, manage **header file declarations (.h)**, and understand how to handle imports between files and potential conflicts that may arise during the compilation process.

## Languages and Technologies

- **C++**: The project is implemented in C++, leveraging advanced language features such as pointers, references, and memory management.
- **CMake**: Used to manage the project build process, generate necessary files for compilation, and simplify dependency management.
- **Graphs**: The project utilizes graphs as the data structure to represent the routes that need optimization.

Key Files:
- **`main.cpp`**: The main executable file that contains the user interaction logic and calls to the algorithms.
- **`extra-funcs.cpp`**: Contains additional helper functions used across the project.
- **`bfs.cpp`**: Contains the implementation of the **Breadth-First Search (BFS)** algorithm.
- **`dfs.cpp`**: Contains the implementation of the **Depth-First Search (DFS)** algorithm.
- **`graph.cpp`**: Defines the graph structure and contains the logic to represent nodes and edges.

## Key Features

- **Graph Representation**: The project implements a graph using nodes and edges, allowing traversal via **DFS** and **BFS**.
- **DFS and BFS Algorithms**: These two algorithms explore the graph from a starting node, one by traversing as deep as possible (DFS) and the other by exploring all neighbors level by level (BFS).
- **CMake Integration**: The project is configured using **CMake** to facilitate easy building and managing dependencies.
- **Advanced C++ Features**: The project incorporates pointers, references, and memory management techniques commonly used in C++.
- **Header File Management**: The project includes proper header file declarations and imports between different files to prevent conflicts and improve modularity.

## Installation and Usage

### Prerequisites

- A C++ compiler (e.g., GCC or Clang).
- **CMake** (to manage the build process).
  
### Installation

1. Clone the repository:

   ```bash
   git clone https://github.com/yourusername/route-optimization-graphs.git
   cd route-optimization-graphs
   ```

2. Create a build directory:

   ```bash
   mkdir build
   cd build
   ```

3. Generate the build files with CMake:

   ```bash
   cmake ..
   ```

4. Compile the project:

   ```bash
   cmake --build .
   ```

5. After compilation, the executable `main` will be created in the `build` directory.

### Running the Project

To run the program, simply execute the following in the `build` directory:

```bash
./main
```

This will start the program, allowing you to interact with the graph and choose between using the **DFS** or **BFS** algorithms.

### Graph Visualization

The graph is visualized using an image that will be included in the README. This will help understand the graph structure and how both **DFS** and **BFS** traverse it.

### Example Usage

1. The program will prompt you to enter a starting node and the destination node.
2. Then the program will output the sequence of nodes visited in both algorithms and total distance between all the visited nodes.
