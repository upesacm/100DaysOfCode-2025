#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int adj[MAX][MAX], visited[MAX], stack[MAX], top = -1;

void dfs(int node, int n) {
    visited[node] = 1;
    for (int i = 0; i < n; i++) {
        if (adj[node][i] && !visited[i]) {
            dfs(i, n);
        }
    }
    stack[++top] = node;
}

int main() {
    int v, e, u, w;
    scanf("%d %d", &v, &e);

    for (int i = 0; i < e; i++) {
        scanf("%d %d", &u, &w);
        adj[u][w] = 1;
    }

    for (int i = 0; i < v; i++) {
        if (!visited[i]) dfs(i, v);
    }

    while (top >= 0) {
        printf("%d ", stack[top--]);
    }
    printf("\n");
    return 0;
}
