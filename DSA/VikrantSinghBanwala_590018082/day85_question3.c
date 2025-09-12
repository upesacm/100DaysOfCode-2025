#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int graph[MAX][MAX];
int visited[MAX];


void dfs(int node, int vertices) {
    visited[node] = 1;
    for (int i = 0; i < vertices; i++) {
        if (graph[node][i] == 1 && !visited[i]) {
            dfs(i, vertices);
        }
    }
}

int countComponents(int vertices) {
    int count = 0;
    for (int i = 0; i < vertices; i++) {
        if (!visited[i]) {
            dfs(i, vertices);
            count++;
        }
    }
    return count;
}


int main() {
    int vertices = 5;
    int edges[][2] = {{0,1},{1,2},{3,4}};
    int edgeCount = sizeof(edges) / sizeof(edges[0]);

    
    for (int i = 0; i < vertices; i++)
        for (int j = 0; j < vertices; j++)
            graph[i][j] = 0;

    
    for (int i = 0; i < edgeCount; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        graph[u][v] = graph[v][u] = 1;
    }

    
    for (int i = 0; i < vertices; i++)
        visited[i] = 0;

    int components = countComponents(vertices);
    printf("Number of connected components: %d\n", components);

    return 0;
}