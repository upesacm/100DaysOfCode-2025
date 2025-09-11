#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

int isBipartite(int V, int edges[][2], int E) {
    int graph[MAX][MAX] = {0};
    int color[MAX];
    for (int i = 0; i < V; i++) color[i] = -1;

    // Build adjacency matrix
    for (int i = 0; i < E; i++) {
        int u = edges[i][0], v = edges[i][1];
        graph[u][v] = 1;
        graph[v][u] = 1;
    }

    // BFS coloring
    for (int start = 0; start < V; start++) {
        if (color[start] == -1) {
            int queue[MAX], front = 0, rear = 0;
            queue[rear++] = start;
            color[start] = 0;

            while (front < rear) {
                int node = queue[front++];
                for (int neighbor = 0; neighbor < V; neighbor++) {
                    if (graph[node][neighbor]) {
                        if (color[neighbor] == -1) {
                            color[neighbor] = 1 - color[node];
                            queue[rear++] = neighbor;
                        } else if (color[neighbor] == color[node]) {
                            return 0; // Not bipartite
                        }
                    }
                }
            }
        }
    }
    return 1; // Bipartite
}
