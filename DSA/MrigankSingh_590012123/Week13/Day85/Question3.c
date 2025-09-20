#include <stdio.h>
#include <stdlib.h>

void dfsUtil(int** adjMatrix, int vertices, int vertex, int* visited) {
    visited[vertex] = 1;
    
    for (int i = 0; i < vertices; i++) {
        if (adjMatrix[vertex][i] && !visited[i]) {
            dfsUtil(adjMatrix, vertices, i, visited);
        }
    }
}

int countComponents(int** adjMatrix, int vertices) {
    int* visited = (int*)calloc(vertices, sizeof(int));
    int count = 0;
    
    for (int i = 0; i < vertices; i++) {
        if (!visited[i]) {
            dfsUtil(adjMatrix, vertices, i, visited);
            count++;
        }
    }
    
    free(visited);
    return count;
}

int main() {
    int vertices, edges;
    printf("Enter number of vertices: ");
    scanf("%d", &vertices);
    printf("Enter number of edges: ");
    scanf("%d", &edges);
    
    int** adjMatrix = (int**)malloc(vertices * sizeof(int*));
    for (int i = 0; i < vertices; i++) {
        adjMatrix[i] = (int*)calloc(vertices, sizeof(int));
    }
    
    printf("Enter %d edges (u v):\n", edges);
    for (int i = 0; i < edges; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adjMatrix[u][v] = 1;
        adjMatrix[v][u] = 1; // Undirected graph
    }
    
    printf("Number of connected components: %d\n", countComponents(adjMatrix, vertices));
    
    for (int i = 0; i < vertices; i++) {
        free(adjMatrix[i]);
    }
    free(adjMatrix);
    return 0;
}
