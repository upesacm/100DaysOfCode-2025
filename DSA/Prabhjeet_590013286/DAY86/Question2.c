#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int graph[MAX][MAX];
int visited[MAX];
int recStack[MAX];

int dfsDirected(int node, int V) {
    visited[node] = 1;
    recStack[node] = 1;

    for (int i = 0; i < V; i++) {
        if (graph[node][i]) {
            if (!visited[i]) {
                if (dfsDirected(i, V)) return 1;
            } else if (recStack[i]) {
                return 1;
            }
        }
    }

    recStack[node] = 0;
    return 0;
}

int hasCycleDirected(int V, int edges[][2], int E) {
    for (int i = 0; i < E; i++) {
        int u = edges[i][0], v = edges[i][1];
        graph[u][v] = 1;
    }

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (dfsDirected(i, V)) return 1;
        }
    }
    return 0;
}
