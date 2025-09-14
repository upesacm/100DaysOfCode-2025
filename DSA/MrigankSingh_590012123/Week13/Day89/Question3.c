#include <stdio.h>
#include <stdlib.h>

struct Stack {
    int* array;
    int top, capacity;
};

struct Stack* createStack(int capacity) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int*)malloc(capacity * sizeof(int));
    return stack;
}

void push(struct Stack* stack, int item) {
    stack->array[++stack->top] = item;
}

int pop(struct Stack* stack) {
    return stack->array[stack->top--];
}

void dfsFill(int** adjMatrix, int vertices, int vertex, int* visited, struct Stack* stack) {
    visited[vertex] = 1;
    
    for (int i = 0; i < vertices; i++) {
        if (adjMatrix[vertex][i] && !visited[i]) {
            dfsFill(adjMatrix, vertices, i, visited, stack);
        }
    }
    
    push(stack, vertex);
}

void dfsSCC(int** adjMatrix, int vertices, int vertex, int* visited) {
    visited[vertex] = 1;
    
    for (int i = 0; i < vertices; i++) {
        if (adjMatrix[vertex][i] && !visited[i]) {
            dfsSCC(adjMatrix, vertices, i, visited);
        }
    }
}

void transposeGraph(int** adjMatrix, int** transpose, int vertices) {
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            transpose[i][j] = adjMatrix[j][i];
        }
    }
}

int kosarajuSCC(int** adjMatrix, int vertices) {
    int* visited = (int*)calloc(vertices, sizeof(int));
    struct Stack* stack = createStack(vertices);
    
    for (int i = 0; i < vertices; i++) {
        if (!visited[i]) {
            dfsFill(adjMatrix, vertices, i, visited, stack);
        }
    }
    
    int** transpose = (int**)malloc(vertices * sizeof(int*));
    for (int i = 0; i < vertices; i++) {
        transpose[i] = (int*)calloc(vertices, sizeof(int));
    }
    transposeGraph(adjMatrix, transpose, vertices);
    
    for (int i = 0; i < vertices; i++) {
        visited[i] = 0;
    }
    
    int sccCount = 0;
    while (stack->top >= 0) {
        int v = pop(stack);
        if (!visited[v]) {
            dfsSCC(transpose, vertices, v, visited);
            sccCount++;
        }
    }
    
    free(visited);
    free(stack->array);
    free(stack);
    for (int i = 0; i < vertices; i++) {
        free(transpose[i]);
    }
    free(transpose);
    return sccCount;
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
    
    int sccCount = kosarajuSCC(adjMatrix, vertices);
    printf("%d\n", sccCount);
    
    for (int i = 0; i < vertices; i++) {
        free(adjMatrix[i]);
    }
    free(adjMatrix);
    return 0;
}
