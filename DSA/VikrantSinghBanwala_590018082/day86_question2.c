#include <stdio.h>
#include <stdlib.h>

int dfs(int v, int *color, int **adj, int *adjSize) {
    color[v] = 1;
    for (int i = 0; i < adjSize[v]; i++) {
        int u = adj[v][i];
        if (color[u] == 0) {
            if (dfs(u, color, adj, adjSize)) return 1;
        } else if (color[u] == 1) {
            return 1;
        }
    }
    color[v] = 2;
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
    }
    int *color = calloc(V, sizeof(int));
    int cycle = 0;
    for (int i = 0; i < V; i++) {
        if (color[i] == 0) {
            if (dfs(i, color, adj, adjSize)) {
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
    free(color);
    return 0;
}
