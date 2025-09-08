#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int adj[MAX][MAX];
int visited[MAX];

void dfs(int v, int V) {
    visited[v] = 1;
    for (int i = 0; i < V; i++) {
        if (adj[v][i] && !visited[i]) {
            dfs(i, V);
        }
    }
}

int countComponents(int V) {
    int count = 0;
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            dfs(i, V);
            count++;
        }
    }
    return count;
}

int main() {
    int V = 5;
    int edges[3][2] = {{0,1},{1,2},{3,4}};

    for (int i = 0; i < 3; i++) {
        int u = edges[i][0], v = edges[i][1];
        adj[u][v] = adj[v][u] = 1;
    }

    printf("Number of Connected Components: %d\n", countComponents(V));

    return 0;
}
