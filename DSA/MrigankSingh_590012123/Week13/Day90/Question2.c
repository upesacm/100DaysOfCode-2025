#include <stdio.h>
#include <stdlib.h>

void checkEulerian(int** adjMatrix, int vertices) {
    int* degree = (int*)calloc(vertices, sizeof(int));
    int oddCount = 0;
    
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            if (adjMatrix[i][j]) {
                degree[i]++;
            }
        }
        if (degree[i] % 2 != 0) {
            oddCount++;
        }
    }
    
    if (oddCount == 0) {
        printf("Eulerian Circuit Exists\n");
    } else if (oddCount == 2) {
        printf("Eulerian Path Exists\n");
    } else {
        printf("No Eulerian Path or Circuit Exists\n");
    }
    
    free(degree);
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
    
    checkEulerian(adjMatrix, vertices);
    
    for (int i = 0; i < vertices; i++) {
        free(adjMatrix[i]);
    }
    free(adjMatrix);
    return 0;
}
