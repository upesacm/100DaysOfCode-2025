#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Edge {
    int src, dest, weight;
};

void bellmanFord(struct Edge* edges, int vertices, int edgeCount, int source, int* distances) {
    for (int i = 0; i < vertices; i++) {
        distances[i] = INT_MAX;
    }
    distances[source] = 0;
    
    for (int i = 0; i < vertices - 1; i++) {
        for (int j = 0; j < edgeCount; j++) {
            int u = edges[j].src;
            int v = edges[j].dest;
            int w = edges[j].weight;
            
            if (distances[u] != INT_MAX && distances[u] + w < distances[v]) {
                distances[v] = distances[u] + w;
            }
        }
    }
    
    for (int i = 0; i < edgeCount; i++) {
        int u = edges[i].src;
        int v = edges[i].dest;
        int w = edges[i].weight;
        
        if (distances[u] != INT_MAX && distances[u] + w < distances[v]) {
            printf("Graph contains negative weight cycle\n");
            return;
        }
    }
}

int main() {
    int vertices, edges, source;
    printf("Enter number of vertices: ");
    scanf("%d", &vertices);
    printf("Enter number of edges: ");
    scanf("%d", &edges);
    
    struct Edge* edgesArray = (struct Edge*)malloc(edges * sizeof(struct Edge));
    
    printf("Enter %d edges (u v weight):\n", edges);
    for (int i = 0; i < edges; i++) {
        scanf("%d %d %d", &edgesArray[i].src, &edgesArray[i].dest, &edgesArray[i].weight);
    }
    
    printf("Enter source vertex: ");
    scanf("%d", &source);
    
    int* distances = (int*)malloc(vertices * sizeof(int));
    bellmanFord(edgesArray, vertices, edges, source, distances);
    
    printf("Distances = [");
    for (int i = 0; i < vertices; i++) {
        if (distances[i] == INT_MAX) printf("INF");
        else printf("%d", distances[i]);
        if (i < vertices - 1) printf(",");
    }
    printf("]\n");
    
    free(edgesArray);
    free(distances);
    return 0;
}
