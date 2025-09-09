#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int adj[MAX][MAX], visited[MAX];

void dfs(int node, int n) {
    visited[node] = 1;
    for (int i = 0; i < n; i++) {
        if (adj[node][i] && !visited[i]) {
            dfs(i, n);
        }
    }
}

int main() {
    int v, e, u, w, components = 0;
    scanf("%d %d", &v, &e);

    for (int i = 0; i < e; i++) {
        scanf("%d %d", &u, &w);
        adj[u][w] = adj[w][u] = 1;
    }

    for (int i = 0; i < v; i++) {
        if (!visited[i]) {
            dfs(i, v);
            components++;
        }
    }

    printf("%d\n", components);
    return 0;
}
