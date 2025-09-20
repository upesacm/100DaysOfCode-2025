#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool hamiltonianPathUtil(int** adjMatrix, int vertices, int* path, int pos, bool* visited) {
    if (pos == vertices) {
        return true;
    }
    
    for (int v = 0; v < vertices; v++) {
        if (!visited[v] && adjMatrix[path[pos-1]][v]) {
            path[pos] = v;
            visited[v] = true;
            
            if (hamiltonianPathUtil(adjMatrix, vertices, path, pos + 1, visited)) {
                return true;
            }
            
            visited[v] = false;
            path[pos] = -1;
        }
    }
    return false;
}

bool hasHamiltonianPath(int** adjMatrix, int vertices) {
    bool* visited = (bool*)calloc(vertices, sizeof(bool));
    int* path = (int*)malloc(vertices * sizeof(int));
    
    for (int i = 0; i < vertices; i++) {
        path[0] = i;
        visited[i] = true;
        
        if (hamiltonianPathUtil(adjMatrix, vertices, path, 1, visited)) {
            free(visited);
            free(path);
            return true;
        }
        
        visited[i] = false;
        path[0] = -1;
    }
    
    free(visited);
    free(path);
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
    
    printf("%s\n", hasHamiltonianPath(adjMatrix, vertices) ? "Yes" : "No");
    
    for (int i = 0; i < vertices; i++) {
        free(adjMatrix[i]);
    }
    free(adjMatrix);
    return 0;
}
