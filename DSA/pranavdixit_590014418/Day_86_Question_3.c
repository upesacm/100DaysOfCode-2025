#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int adj[MAX][MAX];
int visited[MAX];
int stack[MAX];
int top = -1;

void dfs(int v, int V) {
    visited[v] = 1;
    for (int i = 0; i < V; i++) {
        if (adj[v][i] && !visited[i]) {
            dfs(i, V);
        }
    }
    stack[++top] = v;
}

void topologicalSort(int V) {
    for (int i = 0; i < V; i++) {
        if (!visited[i]) dfs(i, V);
    }

    while (top >= 0) {
        printf("%d ", stack[top--]);
    }
    printf("\n");
}

int main() {
    int V = 6;
    int edges[6][2] = {{5,2},{5,0},{4,0},{4,1},{2,3},{3,1}}; // DAG

    for (int i = 0; i < 6; i++) {
        int u = edges[i][0], v = edges[i][1];
        adj[u][v] = 1;
    }

    printf("Topological Sort: ");
    topologicalSort(V);

    return 0;
}
