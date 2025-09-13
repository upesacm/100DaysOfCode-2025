#include <stdio.h>
#include <limits.h>

#define V 100

int minDistance(int dist[], int visited[], int vertices) {
    int min = INT_MAX, min_index;
    for (int v = 0; v < vertices; v++)
        if (!visited[v] && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    return min_index;
}

void dijkstra(int vertices, int edges[][3], int eCount, int src) {
    int graph[V][V];
    int dist[V], visited[V];

    // Initialize graph with no edges
    for (int i = 0; i < vertices; i++)
        for (int j = 0; j < vertices; j++)
            graph[i][j] = 0;

    // Build adjacency matrix
    for (int i = 0; i < eCount; i++) {
        int u = edges[i][0], v = edges[i][1], w = edges[i][2];
        graph[u][v] = w;
        graph[v][u] = w; // remove if directed
    }

    for (int i = 0; i < vertices; i++) {
        dist[i] = INT_MAX;
        visited[i] = 0;
    }

    dist[src] = 0;

    for (int count = 0; count < vertices - 1; count++) {
        int u = minDistance(dist, visited, vertices);
        visited[u] = 1;

        for (int v = 0; v < vertices; v++) {
            if (!visited[v] && graph[u][v] && dist[u] != INT_MAX 
                && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    printf("Distances: ");
    for (int i = 0; i < vertices; i++)
        printf("%d ", dist[i]);
    printf("\n");
}

int main() {
    int vertices = 5;
    int edges[][3] = {{0,1,2},{0,2,4},{1,2,1},{2,3,7},{1,4,3}};
    int eCount = 5;
    int src = 0;

    dijkstra(vertices, edges, eCount, src);
    return 0;
}

