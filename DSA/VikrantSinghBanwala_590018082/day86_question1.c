#include <stdio.h>
#include <stdlib.h>

int dfs(int v, int parent, int *visited, int **adj, int *adjSize) {
    visited[v] = 1;
    for (int i = 0; i < adjSize[v]; i++) {
        int u = adj[v][i];
        if (!visited[u]) {
            if (dfs(u, v, visited, adj, adjSize)) return 1;
        } else if (u != parent) {
            return 1;
        }
    }
    return 0;
}

int main() {
    int V, E;
    scanf("%d", &V);
    scanf("%d", &E);
    int **adj = malloc(V * sizeof(int *));
    int *adjSize = calloc(V, sizeof(int));
    int *adjCap = malloc(V * sizeof(int));
    for (int i = 0; i < V; i++) {
        adjCap[i] = 2;
        adj[i] = malloc(adjCap[i] * sizeof(int));
    }
    for (int i = 0; i < E; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        if (adjSize[a] == adjCap[a]) {
            adjCap[a] *= 2;
            adj[a] = realloc(adj[a], adjCap[a] * sizeof(int));
        }
        adj[a][adjSize[a]++] = b;
        if (adjSize[b] == adjCap[b]) {
            adjCap[b] *= 2;
            adj[b] = realloc(adj[b], adjCap[b] * sizeof(int));
        }
        adj[b][adjSize[b]++] = a;
    }
    int *visited = calloc(V, sizeof(int));
    int cycle = 0;
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (dfs(i, -1, visited, adj, adjSize)) {
                cycle = 1;
                break;
            }
        }
    }
    printf(cycle ? "Yes\n" : "No\n");
    for (int i = 0; i < V; i++) free(adj[i]);
    free(adj);
    free(adjSize);
    free(adjCap);
    free(visited);
    return 0;
}
