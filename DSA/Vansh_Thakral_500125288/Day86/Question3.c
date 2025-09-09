#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int adj[MAX][MAX];
int visited[MAX];
int stack[MAX];
int top = -1;

void dfsTopo(int v, int vertices) {
    visited[v] = 1;
    for (int i = 0; i < vertices; i++) {
        if (adj[v][i] && !visited[i]) {
            dfsTopo(i, vertices);
        }
    }
    stack[++top] = v; // push after visiting all neighbors
}

void topologicalSort(int vertices) {
    for (int i = 0; i < vertices; i++) {
        if (!visited[i])
            dfsTopo(i, vertices);
    }
    while (top >= 0) {
        printf("%d ", stack[top--]);
    }
    printf("\n");
}

int main() {
    int vertices = 6, edges = 6;
    int edgeList[6][2] = {
        {5,2}, {5,0}, {4,0}, {4,1}, {2,3}, {3,1}
    };

    for (int i = 0; i < edges; i++) {
        int u = edgeList[i][0], v = edgeList[i][1];
        adj[u][v] = 1; // directed
    }

    printf("Topological Sort:\n");
    topologicalSort(vertices);

    return 0;
}
