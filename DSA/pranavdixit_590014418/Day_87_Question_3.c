#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 100
#define INF INT_MAX

struct Edge {
    int u, v, w;
};

int dist[MAX];

void bellmanFord(struct Edge edges[], int V, int E, int src) {
    for (int i = 0; i < V; i++) dist[i] = INF;
    dist[src] = 0;

    for (int i = 1; i <= V - 1; i++) {
        for (int j = 0; j < E; j++) {
            int u = edges[j].u;
            int v = edges[j].v;
            int w = edges[j].w;
            if (dist[u] != INF && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }

    for (int j = 0; j < E; j++) {
        int u = edges[j].u;
        int v = edges[j].v;
        int w = edges[j].w;
        if (dist[u] != INF && dist[u] + w < dist[v]) {
            printf("Graph contains negative weight cycle\n");
            return;
        }
    }
}

int main() {
    int V = 5, E = 8;
    struct Edge edges[] = {
        {0,1,-1},{0,2,4},{1,2,3},{1,3,2},{1,4,2},{3,2,5},{3,1,1},{4,3,-3}
    };

    int src = 0;
    bellmanFord(edges, V, E, src);

    printf("Distances: ");
    for (int i = 0; i < V; i++) {
        printf("%d ", dist[i] == INF ? 9999 : dist[i]);
    }
    printf("\n");

    return 0;
}
