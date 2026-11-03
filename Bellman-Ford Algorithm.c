#include <stdio.h>
#include <limits.h>

#define V 5
#define E 8

typedef struct {
    int src;
    int dest;
    int weight;
} Edge;

void bellmanFord(Edge edges[], int source) {

    int distance[V];

    // Step 1: Initialize distances
    for (int i = 0; i < V; i++) {
        distance[i] = INT_MAX;
    }

    distance[source] = 0;

    // Step 2: Relax all edges V-1 times
    for (int i = 1; i <= V - 1; i++) {

        for (int j = 0; j < E; j++) {

            int u = edges[j].src;
            int v = edges[j].dest;
            int weight = edges[j].weight;

            if (distance[u] != INT_MAX &&
                distance[u] + weight < distance[v]) {

                distance[v] = distance[u] + weight;
            }
        }
    }

    // Step 3: Check for negative weight cycle
    for (int j = 0; j < E; j++) {

        int u = edges[j].src;
        int v = edges[j].dest;
        int weight = edges[j].weight;

        if (distance[u] != INT_MAX &&
            distance[u] + weight < distance[v]) {

            printf("Negative weight cycle detected!\n");
            return;
        }
    }

    // Print shortest distances
    printf("Vertex\tShortest Distance\n");

    for (int i = 0; i < V; i++) {

        if (distance[i] == INT_MAX)
            printf("%d\tINF\n", i);
        else
            printf("%d\t%d\n", i, distance[i]);
    }
}

int main() {

    Edge edges[E] = {

        {0, 1, 6},
        {0, 2, 7},
        {1, 2, 8},
        {1, 3, 5},
        {1, 4, -4},
        {2, 3, -3},
        {2, 4, 9},
        {4, 3, 7}
    };

    int source = 0;

    printf("Bellman-Ford Algorithm\n");
    printf("======================\n\n");

    printf("Source Vertex: %d\n\n", source);

    bellmanFord(edges, source);

    return 0;
}
