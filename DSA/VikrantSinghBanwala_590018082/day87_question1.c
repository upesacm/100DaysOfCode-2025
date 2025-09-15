#include <stdio.h>
#include <stdlib.h>

#define MAX 100

void bfs(int vertices, int edges[][2], int edgeCount, int source, int distances[]) {
    int adj[MAX][MAX] = {0};
    int visited[MAX] = {0};
    int queue[MAX], front = 0, rear = 0;

    for (int i = 0; i < edgeCount; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    
    for (int i = 0; i < vertices; i++) {
        distances[i] = -1;
    }

    
    queue[rear++] = source;
    visited[source] = 1;
    distances[source] = 0;

    while (front < rear) {
        int current = queue[front++];
        for (int i = 0; i < vertices; i++) {
            if (adj[current][i] && !visited[i]) {
                visited[i] = 1;
                distances[i] = distances[current] + 1;
                queue[rear++] = i;
            }
        }
    }
}

int main() {
    int vertices = 6;
    int edges[][2] = {{0,1},{0,2},{1,3},{2,4},{4,5}};
    int edgeCount = sizeof(edges) / sizeof(edges[0]);
    int source = 0;
    int distances[MAX];

    bfs(vertices, edges, edgeCount, source, distances);

    for (int i = 0; i < vertices; i++) {
        printf("%d ", distances[i]);
    }
    return 0;
}