#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int adj[MAX][MAX];
int visited[MAX];
int recStack[MAX];

int dfs(int v, int V) {
    visited[v] = 1;
    recStack[v] = 1;

    for (int i = 0; i < V; i++) {
        if (adj[v][i]) {
            if (!visited[i] && dfs(i, V)) return 1;
            else if (recStack[i]) return 1;
        }
    }

    recStack[v] = 0;
    return 0;
}

int hasCycle(int V) {
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (dfs(i, V)) return 1;
        }
    }
    return 0;
}

int main() {
    int V = 3;
    int edges[3][2] = {{0,1},{1,2},{2,0}}; // change edges to test

    for (int i = 0; i < 3; i++) {
        int u = edges[i][0], v = edges[i][1];
        adj[u][v] = 1;
    }

    if (hasCycle(V)) printf("Yes\n");
    else printf("No\n");

    return 0;
}
