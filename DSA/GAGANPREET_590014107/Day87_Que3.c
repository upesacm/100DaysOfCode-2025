#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define MAX 100

typedef struct {
    int u, v, w;
} Edge;

bool bellmanFord(int vertices, Edge edges[], int edgeCount, int source, int dist[]) {

    for (int i = 0; i < vertices; i++) {
        dist[i] = INT_MAX;
    }
    dist[source] = 0;

    
    for (int i = 1; i < vertices; i++) {
        for (int j = 0; j < edgeCount; j++) {
            int u = edges[j].u;
            int v = edges[j].v;
            int w = edges[j].w;
            if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }

    
    for (int j = 0; j < edgeCount; j++) {
        int u = edges[j].u;
        int v = edges[j].v;
        int w = edges[j].w;
        if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
            return false; 
        }
    }

    return true;
}
int main() {
    int vertices = 5;
    Edge edges[] = {
        {0,1,-1},{0,2,4},{1,2,3},{1,3,2},
        {1,4,2},{3,2,5},{3,1,1},{4,3,-3}
    };
    int edgeCount = sizeof(edges) / sizeof(edges[0]);
    int source = 0;
    int dist[MAX];

    if (bellmanFord(vertices, edges, edgeCount, source, dist)) {
        for (int i = 0; i < vertices; i++) {
            printf("%d ", dist[i]);
        }
    } else {
        printf("Negative weight cycle detected.\n");
    }

    return 0;
}
