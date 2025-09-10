#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int adj[MAX][MAX], visited[MAX];

void dfs(int node, int n) {
    visited[node] = 1;
    printf("%d ", node);
    for (int i = 0; i < n; i++) {
        if (adj[node][i] && !visited[i]) {
            dfs(i, n);
        }
    }
}

int main() {
    int v, e, u, w;
    scanf("%d %d", &v, &e);

    for (int i = 0; i < e; i++) {
        scanf("%d %d", &u, &w);
        adj[u][w] = adj[w][u] = 1;
    }

    dfs(0, v);
    return 0;
}
