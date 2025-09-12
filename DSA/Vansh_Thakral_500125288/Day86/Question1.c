#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int adj[MAX][MAX];
int visited[MAX];

int dfs(int v, int parent, int vertices) {
    visited[v] = 1;

    for (int i = 0; i < vertices; i++) {
        if (adj[v][i]) {
            if (!visited[i]) {
                if (dfs(i, v, vertices))
                    return 1;
            } else if (i != parent) {
                return 1; 
            }
        }
    }
    return 0;
}

int hasCycle(int vertices) {
    for (int i = 0; i < vertices; i++) {
        if (!visited[i]) {
            if (dfs(i, -1, vertices))
                return 1;
        }
    }
    return 0;
}

int main() {
    int vertices = 3, edges = 3;
    int edgeList[3][2] = {{0,1},{1,2},{2,0}};

    for (int i = 0; i < edges; i++) {
        int u = edgeList[i][0], v = edgeList[i][1];
        adj[u][v] = adj[v][u] = 1; 
    }

    if (hasCycle(vertices)) printf("Yes\n");
    else printf("No\n");

    return 0;
}
