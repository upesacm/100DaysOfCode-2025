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

void dfsTopoUtil(int** adjMatrix, int vertices, int vertex, bool* visited, struct Stack* stack) {
    visited[vertex] = true;
    
    for (int i = 0; i < vertices; i++) {
        if (adjMatrix[vertex][i] && !visited[i]) {
            dfsTopoUtil(adjMatrix, vertices, i, visited, stack);
        }
    }
    
    push(stack, vertex);
}

void topologicalSort(int** adjMatrix, int vertices) {
    bool* visited = (bool*)calloc(vertices, sizeof(bool));
    struct Stack* stack = createStack(vertices);
    
    for (int i = 0; i < vertices; i++) {
        if (!visited[i]) {
            dfsTopoUtil(adjMatrix, vertices, i, visited, stack);
        }
    }
    
    printf("Topological Sort: ");
    while (stack->top >= 0) {
        printf("%d ", pop(stack));
    }
    printf("\n");
    
    free(visited);
    free(stack->array);
    free(stack);
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
    
    topologicalSort(adjMatrix, vertices);
    
    for (int i = 0; i < vertices; i++) {
        free(adjMatrix[i]);
    }
    free(adjMatrix);
    return 0;
}
