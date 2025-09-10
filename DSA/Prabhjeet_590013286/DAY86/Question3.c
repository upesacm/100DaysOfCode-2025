#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int graph[MAX][MAX];
int visited[MAX];
int result[MAX];
int index = 0;

void dfsTopo(int node, int V) {
    visited[node] = 1;
    for (int i = 0; i < V; i++) {
        if (graph[node][i] && !visited[i]) {
            dfsTopo(i, V);
        }
    }
    result[index++] = node;
}

void topologicalSort(int V, int edges[][2], int E) {
    for (int i = 0; i < E; i++) {
        int u = edges[i][0], v = edges[i][1];
        graph[u][v] = 1;
    }

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            dfsTopo(i, V);
        }
    }

    for (int i = index - 1; i >= 0; i--) {
        printf("%d ", result[i]);
    }
    printf("\n");
}
