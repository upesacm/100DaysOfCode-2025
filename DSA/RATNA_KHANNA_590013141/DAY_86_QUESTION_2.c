#include <stdio.h>
#include <stdlib.h>

int dfs(int node, int v, int adj[v][v], int visited[v], int recStack[v]) {
    visited[node] = 1;
    recStack[node] = 1;

    for (int i = 0; i < v; i++) {
        if (adj[node][i]) {
            if (!visited[i] && dfs(i, v, adj, visited, recStack)) return 1;
            else if (recStack[i]) return 1;
        }
    }

    recStack[node] = 0;
    return 0;
}
