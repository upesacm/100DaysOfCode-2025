#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int adj[MAX][MAX];
int visited[MAX];

void dfsUtil(int v, int V) {
    visited[v] = 1;
    printf("%d ", v);
    for (int i = 0; i < V; i++) {
        if (adj[v][i] && !visited[i]) {
            dfsUtil(i, V);
        }
    }
}

void dfs(int start, int V) {
    for (int i = 0; i < V; i++) visited[i] = 0;
    dfsUtil(start, V);
    printf("\n");
}

int main() {
    int V, E;
    scanf("%d %d", &V, &E);
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            adj[i][j] = 0;

    for (int i = 0; i < E; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    dfs(0, V);
    return 0;
}
