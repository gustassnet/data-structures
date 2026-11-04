# Graph Traversal in C

## 1. Introduction

This project implements graph traversal using the Breadth-First Search (BFS) algorithm in C.

The graph is represented using an adjacency matrix and loaded from a text file. The BFS algorithm uses a queue to traverse the graph, identify tree edges and construct a traversal tree starting from a selected vertex.

## 2. Features

- Graph representation using an adjacency matrix.
- Loading graph data from a text file.
- Breadth-First Search (BFS) traversal.
- Tracking visited vertices.
- Recording parent vertices and traversal levels.
- Printing the edges of the BFS spanning tree.
- Displaying the resulting tree structure.

## 3. Implementation Details

### Graph Representation

The graph is represented using a `Graph` structure:

```c
typedef struct Graph {
    unsigned n;
    unsigned *V;
    unsigned **Matrix;
} Graph;
```

- `n` – number of vertices in the graph.
- `V` – array containing vertex values.
- `Matrix` – adjacency matrix representing connections between vertices.

The adjacency matrix is dynamically allocated using `malloc()` and `calloc()`.

### Graph Loading

The `get_graph()` function reads graph data from a text file.

The file contains:

1. Number of vertices.
2. Vertex values.
3. Adjacency matrix.

The function allocates memory for the graph, reads its contents and returns the initialized graph structure.

### Breadth-First Search (BFS)

The `find_tree()` function implements the Breadth-First Search algorithm.

The traversal starts from a specified vertex and uses a queue to process vertices in FIFO order.

During traversal:

- A queue stores vertices waiting to be processed.
- An array tracks visited vertices.
- The `parent` array stores the parent of each discovered vertex.
- The `level` array stores the distance from the starting vertex.

When an unvisited adjacent vertex is found, it is marked as visited, added to the queue and connected to its parent.

The algorithm prints the edges of the resulting traversal tree and displays its hierarchical structure.

### Memory Management

Graph data is dynamically allocated and released using `malloc()`, `calloc()` and `free()`.

The `free_graph()` function releases the memory allocated for the graph.

## 4. Function Documentation

### `Graph get_graph(const char *file_name)`

Loads a graph from a text file and returns an initialized `Graph` structure.

**Parameters:**
- `file_name` – path to the input file.

**Returns:**
- An initialized `Graph` structure.

### `void free_graph(Graph *graph)`

Releases dynamically allocated memory used by the graph.

**Parameters:**
- `graph` – pointer to the graph structure.

### `void find_tree(Graph *graph, Item_type v)`

Performs BFS traversal starting from the specified vertex and prints the resulting traversal tree.

**Parameters:**
- `graph` – pointer to the graph.
- `v` – starting vertex.

## 5. Building and Running

### Build

Compile the project using the provided Makefile:

```bash
make
```

### Run using the Windows Script

The project includes a go.cmd script that automates compilation and test execution.

```cmd
go.cmd
```

The script:

- Compiles the files using Makefile.
- Executes the generated test.exe.
- Redirects standard output to rez1.txt and rez2.txt.