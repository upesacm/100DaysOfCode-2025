#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int adj[MAX][MAX];
int visited[MAX];
int recStack[MAX];

int dfsDirected(int v, int vertices) {
    visited[v] = 1;
    recStack[v] = 1;

    for (int i = 0; i < vertices; i++) {
        if (adj[v][i]) {
            if (!visited[i] && dfsDirected(i, vertices))
                return 1;
            else if (recStack[i])
                return 1; // Found a back edge → cycle
        }
    }

    recStack[v] = 0;
    return 0;
}

int hasCycleDirected(int vertices) {
    for (int i = 0; i < vertices; i++) {
        if (!visited[i]) {
            if (dfsDirected(i, vertices))
                return 1;
        }
    }
    return 0;
}

int main() {
    int vertices = 3, edges = 3;
    int edgeList[3][2] = {{0,1},{1,2},{2,0}}; // cycle

    for (int i = 0; i < edges; i++) {
        int u = edgeList[i][0], v = edgeList[i][1];
        adj[u][v] = 1; // directed
    }

    if (hasCycleDirected(vertices)) printf("Yes\n");
    else printf("No\n");

    return 0;
}
