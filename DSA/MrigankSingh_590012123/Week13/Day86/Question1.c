#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool dfsCycleUtil(int** adjMatrix, int vertices, int vertex, int parent, bool* visited) {
    visited[vertex] = true;
    
    for (int i = 0; i < vertices; i++) {
        if (adjMatrix[vertex][i]) {
            if (!visited[i]) {
                if (dfsCycleUtil(adjMatrix, vertices, i, vertex, visited)) {
                    return true;
                }
            } else if (i != parent) {
                return true;
            }
        }
    }
    return false;
}

bool hasCycle(int** adjMatrix, int vertices) {
    bool* visited = (bool*)calloc(vertices, sizeof(bool));
    
    for (int i = 0; i < vertices; i++) {
        if (!visited[i]) {
            if (dfsCycleUtil(adjMatrix, vertices, i, -1, visited)) {
                free(visited);
                return true;
            }
        }
    }
    
    free(visited);
    return false;
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
    
    printf("%s\n", hasCycle(adjMatrix, vertices) ? "Yes" : "No");
    
    for (int i = 0; i < vertices; i++) {
        free(adjMatrix[i]);
    }
    free(adjMatrix);
    return 0;
}
