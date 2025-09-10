#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int adj[MAX][MAX];
int visited[MAX];

void dfsComponent(int v, int V) {
    visited[v] = 1;
    for (int i = 0; i < V; i++) {
        if (adj[v][i] && !visited[i]) {
            dfsComponent(i, V);
        }
    }
}

int countComponents(int V) {
    for (int i = 0; i < V; i++) visited[i] = 0;
    int count = 0;
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            dfsComponent(i, V);
            count++;
        }
    }
    return count;
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

    printf("%d\n", countComponents(V));
    return 0;
}
