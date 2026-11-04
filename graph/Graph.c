#include <stdio.h>
#include <stdlib.h>
#include "Graph.h"

Graph get_graph(const char *file_name) {
    Graph graph;
    FILE *fptr = fopen(file_name, "r");
    if (!fptr) {
        perror("Failed to open file");
        exit(EXIT_FAILURE);
    }

    fscanf(fptr, "%u", &graph.n);

    // The memory comes to mind
    graph.V = malloc(graph.n * sizeof(unsigned));
    graph.Matrix = malloc(graph.n * sizeof(unsigned *));
    for (unsigned i = 0; i < graph.n; ++i) {
        graph.Matrix[i] = calloc(graph.n, sizeof(unsigned));
    }

    // Reads the vertices
    for (unsigned i = 0; i < graph.n; ++i) {
        fscanf(fptr, "%u", &graph.V[i]);
    }

    // Read the adjacency matrix
    for (unsigned i = 0; i < graph.n; ++i) {
        for (unsigned j = 0; j < graph.n; ++j) {
            fscanf(fptr, "%u", &graph.Matrix[i][j]);
        }
    }

    fclose(fptr);
    return graph;
}

void free_graph(Graph *graph) {
    free(graph->V);
    for (unsigned i = 0; i < graph->n - 1; ++i) {
        free(graph->Matrix[i]);
    }
    free(graph->Matrix);
}

void find_tree(Graph *graph, Item_type v) {
    printf("Tree edges: ");

    int *parent = malloc(graph->n * sizeof(int));
    int *level = malloc(graph->n * sizeof(int));

    unsigned naujas[graph->n];
    for (unsigned i = 0; i < graph->n; ++i) {
        naujas[i] = 1;
        parent[i] = -1;
        level[i] = -1;
    }

    Queue queue = init_queue();
    enqueue(&queue, v);
    naujas[v-1] = 0;
    level[v - 1] = 0;
    
    unsigned count = 0;

    while (count + 1 < graph->n) {
        Item_type current = dequeue(&queue);

        for (int i = 0; i < graph->n; ++i) {
            // If the adjacent p is new
            if (graph->Matrix[current-1][i] && naujas[i]) {
                if (count != 0) {
                    printf(", ");
                }
                printf("(%u,%u)", current, i+1);
                enqueue(&queue, i + 1);
                naujas[i] = 0;
                count++;

                parent[i] = current - 1;
                level[i] = level[current - 1] + 1;
            }
        }
    }
    printf("\n");

    // Printing a tree
    for (unsigned i = 0; i < graph->n; ++i) {
        if (!naujas[i]) {
            for (int j = 0; j < level[i]; ++j) {
                printf("  ");
            }
            printf("%u\n", i + 1);
        }
    }
}