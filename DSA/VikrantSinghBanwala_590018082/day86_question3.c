#include <stdio.h>
#include <stdlib.h>

void dfs(int v, int *visited, int **adj, int *adjSize, int *stack, int *top) {
    visited[v] = 1;
    for (int i = 0; i < adjSize[v]; i++) {
        int u = adj[v][i];
        if (!visited[u]) dfs(u, visited, adj, adjSize, stack, top);
    }
    stack[(*top)++] = v;
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
    int *visited = calloc(V, sizeof(int));
    int *stack = malloc(V * sizeof(int));
    int top = 0;
    for (int i = 0; i < V; i++) {
        if (!visited[i]) dfs(i, visited, adj, adjSize, stack, &top);
    }
    for (int i = top - 1; i >= 0; i--) {
        printf("%d", stack[i]);
        if (i > 0) printf(" ");
    }
    printf("\n");
    for (int i = 0; i < V; i++) free(adj[i]);
    free(adj);
    free(adjSize);
    free(adjCap);
    free(visited);
    free(stack);
    return 0;
}
