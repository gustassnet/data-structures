#ifndef GRAPH_H
#define GRAPH_H

#include "Queue.h"

typedef struct Graph {
    unsigned n;         // Number of vertices
    unsigned *V;        // Set of vertices
    unsigned **Matrix;  // Adjacency matrix
} Graph;

Graph get_graph();
void free_graph(Graph *graph);
void find_tree(Graph *graph, Item_type v);

#endif