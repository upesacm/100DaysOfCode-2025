#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int graph[MAX][MAX];
int visited[MAX];

int dfs(int node, int parent, int V) {
    visited[node] = 1;
    for (int i = 0; i < V; i++) {
        if (graph[node][i]) {
            if (!visited[i]) {
                if (dfs(i, node, V)) return 1;
            } else if (i != parent) {
                return 1;
            }
        }
    }
    return 0;
}

int hasCycleUndirected(int V, int edges[][2], int E) {
    for (int i = 0; i < E; i++) {
        int u = edges[i][0], v = edges[i][1];
        graph[u][v] = graph[v][u] = 1;
    }

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (dfs(i, -1, V)) return 1;
        }
    }
    return 0;
}
