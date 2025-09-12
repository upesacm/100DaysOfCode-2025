#include <stdio.h>
#include <stdlib.h>

void dfs(int node, int v, int adj[v][v], int visited[v], int stack[], int *top) {
    visited[node] = 1;
    for (int i = 0; i < v; i++) {
        if (adj[node][i] && !visited[i]) {
            dfs(i, v, adj, visited, stack, top);
        }
    }
    stack[(*top)++] = node;
}

int main() {
    int v, e;
    printf("Enter number of vertices: ");
    scanf("%d", &v);
    printf("Enter number of edges: ");
    scanf("%d", &e);

    int adj[v][v];
    for (int i = 0; i < v; i++) {
        for (int j = 0; j < v; j++) adj[i][j] = 0;
    }

    printf("Enter directed edges (u v):\n");
    for (int i = 0; i < e; i++) {
        int u, w;
        scanf("%d %d", &u, &w);
        adj[u][w] = 1;
    }

    int visited[v];
    for (int i = 0; i < v; i++) visited[i] = 0;

    int stack[v], top = 0;
    for (int i = 0; i < v; i++) {
        if (!visited[i]) dfs(i, v, adj, visited, stack, &top);
    }

    printf("Topological Sort: ");
    for (int i = top - 1; i >= 0; i--) printf("%d ", stack[i]);
    printf("\n");

    return 0;
}
