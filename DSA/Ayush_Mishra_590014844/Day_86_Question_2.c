#include <stdio.h>
#include <stdlib.h>

#define MAX 999

int adj[MAX][MAX], visited[MAX], recStack[MAX];

int dfs(int v, int n) {
    visited[v] = 1;
    recStack[v] = 1;

    for (int i = 0; i < n; i++) {
        if (adj[v][i]) {
            if (!visited[i] && dfs(i, n)) return 1;
            else if (recStack[i]) return 1;
        }
    }

    recStack[v] = 0;
    return 0;
}

int main() {
    int n, e;
    scanf("%d %d", &n, &e);

    for (int i = 0; i < e; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
    }

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (dfs(i, n)) {
                printf("Yes\n");
                return 0;
            }
        }
    }
    printf("No\n");
    return 0;
}
