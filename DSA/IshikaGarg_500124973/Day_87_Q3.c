#include <stdio.h>
#include <limits.h>

#define INF 100000000

typedef struct {
    int u, v, w;
} Edge;

void bellmanFord(int vertices, Edge edges[], int eCount, int src) {
    int dist[vertices];

    for (int i = 0; i < vertices; i++)
        dist[i] = INF;
    dist[src] = 0;

    // Relax edges V-1 times
    for (int i = 1; i <= vertices - 1; i++) {
        for (int j = 0; j < eCount; j++) {
            int u = edges[j].u;
            int v = edges[j].v;
            int w = edges[j].w;
            if (dist[u] != INF && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }

    // Check negative cycle
    for (int j = 0; j < eCount; j++) {
        int u = edges[j].u;
        int v = edges[j].v;
        int w = edges[j].w;
        if (dist[u] != INF && dist[u] + w < dist[v]) {
            printf("Graph contains negative weight cycle\n");
            return;
        }
    }

    printf("Distances: ");
    for (int i = 0; i < vertices; i++)
        printf("%d ", dist[i]);
    printf("\n");
}

int main() {
    int vertices = 5;
    Edge edges[] = {
        {0,1,-1},{0,2,4},{1,2,3},{1,3,2},
        {1,4,2},{3,2,5},{3,1,1},{4,3,-3}
    };
    int eCount = 8;
    int src = 0;

    bellmanFord(vertices, edges, eCount, src);
    return 0;
}

