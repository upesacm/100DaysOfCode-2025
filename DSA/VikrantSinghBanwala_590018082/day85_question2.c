#include <stdio.h>
#include <stdlib.h>

#define MAX 100


int graph[MAX][MAX];
int visited[MAX];

void dfs(int node, int vertices) {
    visited[node] = 1;
    printf("%d ", node);

    for (int i = 0; i < vertices; i++) {
        if (graph[node][i] == 1 && !visited[i]) {
            dfs(i, vertices);
        }
    }
}


int main() {
    int vertices = 5;
    int edges[][2] = {{0,1},{0,2},{1,3},{2,4}};
    int edgeCount = sizeof(edges) / sizeof(edges[0]);

    // Initialize graph
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

    printf("DFS Traversal starting from node 0:\n");
    dfs(0, vertices);

    return 0;
}