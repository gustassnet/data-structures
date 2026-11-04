#include <stdio.h>
#include <stdlib.h>
#include "Graph.h"
#include "Queue.h"

int main(int argc, char *argv[]) {

    if (argc < 2) {
        fprintf(stderr, "Usage: %s <file_name>\n", argv[0]);
        return 1;
    }

    const char *file_name = argv[1];

    Graph graph = get_graph(file_name);

    // Bet kuri virsune
    Item_type r = 2;
    find_tree(&graph, r);
    free_graph(&graph);

    return 0;
}