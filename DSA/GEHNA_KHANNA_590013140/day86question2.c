#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int adj[MAX][MAX], visited[MAX], recStack[MAX];

int dfs(int node, int n) {
    visited[node] = 1;
    recStack[node] = 1;

    for (int i = 0; i < n; i++) {
        if (adj[node][i]) {
            if (!visited[i] && dfs(i, n)) return 1;
            else if (recStack[i]) return 1;
        }
    }

    recStack[node] = 0;
    return 0;
}

int main() {
    int v, e, u, w;
    scanf("%d %d", &v, &e);

    for (int i = 0; i < e; i++) {
        scanf("%d %d", &u, &w);
        adj[u][w] = 1;
    }

    for (int i = 0; i < v; i++) {
        if (!visited[i]) {
            if (dfs(i, v)) {
                printf("Yes\n");
                return 0;
            }
        }
    }
    printf("No\n");
    return 0;
}
