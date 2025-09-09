#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int adj[MAX][MAX], visited[MAX];

int dfs(int node, int parent, int n) {
    visited[node] = 1;
    for (int i = 0; i < n; i++) {
        if (adj[node][i]) {
            if (!visited[i]) {
                if (dfs(i, node, n)) return 1;
            }
            else if (i != parent) {
                return 1; // found back edge
            }
        }
    }
    return 0;
}

int main() {
    int v, e, u, w;
    scanf("%d %d", &v, &e);

    for (int i = 0; i < e; i++) {
        scanf("%d %d", &u, &w);
        adj[u][w] = adj[w][u] = 1;
    }

    for (int i = 0; i < v; i++) {
        if (!visited[i]) {
            if (dfs(i, -1, v)) {
                printf("Yes\n");
                return 0;
            }
        }
    }
    printf("No\n");
    return 0;
}
