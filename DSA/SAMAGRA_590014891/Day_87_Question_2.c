#include <stdio.h>
#include <limits.h>

#define VMAX 100

int minDistance(int dist[], int visited[], int V) {
    int min = INT_MAX, idx = -1;
    for (int v = 0; v < V; v++) {
        if (!visited[v] && dist[v] <= min) {
            min = dist[v];
            idx = v;
        }
    }
    return idx;
}

void dijkstra(int V, int graph[VMAX][VMAX], int src) {
    int dist[VMAX], visited[VMAX];
    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        visited[i] = 0;
    }
    dist[src] = 0;

    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, visited, V);
        visited[u] = 1;
        for (int v = 0; v < V; v++) {
            if (!visited[v] && graph[u][v] && dist[u] != INT_MAX &&
                dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    printf("Distances: ");
    for (int i = 0; i < V; i++) printf("%d ", dist[i]);
    printf("\n");
}

int main() {
    int V = 5;
    int graph[VMAX][VMAX] = {0};
    int edges[][3] = {{0,1,2},{0,2,4},{1,2,1},{2,3,7},{1,4,3}};
    int E = 5, src = 0;

    for (int i = 0; i < E; i++) {
        int u = edges[i][0], v = edges[i][1], w = edges[i][2];
        graph[u][v] = w;
        graph[v][u] = w; 
    }

    dijkstra(V, graph, src);
    return 0;
}
