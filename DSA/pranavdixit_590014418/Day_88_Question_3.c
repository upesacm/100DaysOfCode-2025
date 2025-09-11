#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int adj[MAX][MAX];
int color[MAX];

int isBipartiteUtil(int v, int V) {
    for (int u = 0; u < V; u++) {
        if (adj[v][u]) {
            if (color[u] == -1) {
                color[u] = 1 - color[v];
                if (!isBipartiteUtil(u, V)) return 0;
            } else if (color[u] == color[v]) {
                return 0;
            }
        }
    }
    return 1;
}

int isBipartite(int V) {
    for (int i = 0; i < V; i++) color[i] = -1;

    for (int i = 0; i < V; i++) {
        if (color[i] == -1) {
            color[i] = 0;
            if (!isBipartiteUtil(i, V)) return 0;
        }
    }
    return 1;
}

int main() {
    int V = 4;
    int edges[4][2] = {{0,1},{1,2},{2,3},{3,0}};

    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            adj[i][j] = 0;

    for (int i = 0; i < 4; i++) {
        int u = edges[i][0], v = edges[i][1];
        adj[u][v] = adj[v][u] = 1;
    }

    if (isBipartite(V)) printf("Yes\n");
    else printf("No\n");

    return 0;
}
