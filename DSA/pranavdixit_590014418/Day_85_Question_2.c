#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int adj[MAX][MAX];
int visited[MAX];

void dfs(int v, int V) {
    visited[v] = 1;
    printf("%d ", v);

    for (int i = 0; i < V; i++) {
        if (adj[v][i] && !visited[i]) {
            dfs(i, V);
        }
    }
}

int main() {
    int V = 5;
    int edges[4][2] = {{0,1},{0,2},{1,3},{2,4}};

    for (int i = 0; i < 4; i++) {
        int u = edges[i][0], v = edges[i][1];
        adj[u][v] = adj[v][u] = 1;
    }

    printf("DFS Traversal: ");
    dfs(0, V);
    printf("\n");

    return 0;
}
