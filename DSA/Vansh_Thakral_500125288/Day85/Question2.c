#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int adj[MAX][MAX];
int visited[MAX];

void dfs(int v, int vertices) {
    visited[v] = 1;
    printf("%d ", v);

    for (int i = 0; i < vertices; i++) {
        if (adj[v][i] && !visited[i]) {
            dfs(i, vertices);
        }
    }
}

int main() {
    int vertices = 5, edges = 4;
    int edgeList[4][2] = {{0,1},{0,2},{1,3},{2,4}};

    for (int i = 0; i < edges; i++) {
        int u = edgeList[i][0], v = edgeList[i][1];
        adj[u][v] = adj[v][u] = 1;  // undirected
    }

    printf("DFS Traversal starting from node 0:\n");
    dfs(0, vertices);
    printf("\n");

    return 0;
}
