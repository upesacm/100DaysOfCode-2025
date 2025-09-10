#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

int adj[MAX][MAX], visited[MAX], stack[MAX], top = -1;

void dfs(int v, int n) {
    visited[v] = 1;
    for (int i = 0; i < n; i++) {
        if (adj[v][i] && !visited[i]) {
            dfs(i, n);
        }
    }
    stack[++top] = v;
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
            dfs(i, n);
        }
    }

    for (int i = top; i >= 0; i--) {
        printf("%d ", stack[i]);
    }
    printf("\n");
    return 0;
}
