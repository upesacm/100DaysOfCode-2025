#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool dfsCycleUtil(int** adjMatrix, int vertices, int vertex, bool* visited, bool* recStack) {
    visited[vertex] = true;
    recStack[vertex] = true;
    
    for (int i = 0; i < vertices; i++) {
        if (adjMatrix[vertex][i]) {
            if (!visited[i]) {
                if (dfsCycleUtil(adjMatrix, vertices, i, visited, recStack)) {
                    return true;
                }
            } else if (recStack[i]) {
                return true;
            }
        }
    }
    
    recStack[vertex] = false;
    return false;
}

bool hasCycle(int** adjMatrix, int vertices) {
    bool* visited = (bool*)calloc(vertices, sizeof(bool));
    bool* recStack = (bool*)calloc(vertices, sizeof(bool));
    
    for (int i = 0; i < vertices; i++) {
        if (!visited[i]) {
            if (dfsCycleUtil(adjMatrix, vertices, i, visited, recStack)) {
                free(visited);
                free(recStack);
                return true;
            }
        }
    }
    
    free(visited);
    free(recStack);
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
        adjMatrix[u][v] = 1; // Directed graph
    }
    
    printf("%s\n", hasCycle(adjMatrix, vertices) ? "Yes" : "No");
    
    for (int i = 0; i < vertices; i++) {
        free(adjMatrix[i]);
    }
    free(adjMatrix);
    return 0;
}
