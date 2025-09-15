#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Stack structure for topological sort
typedef struct Stack {
    int* array;
    int top;
    unsigned capacity;
} Stack;

Stack* createStack(unsigned capacity) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int*)malloc(stack->capacity * sizeof(int));
    return stack;
}

void push(Stack* stack, int item) {
    stack->array[++stack->top] = item;
}

int pop(Stack* stack) {
    return stack->array[stack->top--];
}

bool isEmpty(Stack* stack) {
    return stack->top == -1;
}

// Same Node and Graph structures as above
typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct Graph {
    int vertices;
    Node** adjList;
} Graph;

Node* createNode(int v) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = v;
    newNode->next = NULL;
    return newNode;
}

Graph* createGraph(int vertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->vertices = vertices;
    graph->adjList = (Node**)malloc(vertices * sizeof(Node*));
    for (int i = 0; i < vertices; i++) {
        graph->adjList[i] = NULL;
    }
    return graph;
}

void addDirectedEdge(Graph* graph, int u, int v) {
    Node* newNode = createNode(v);
    newNode->next = graph->adjList[u];
    graph->adjList[u] = newNode;
}

void topologicalSortDFS(Graph* graph, int v, bool visited[], Stack* stack) {
    visited[v] = true;
    Node* current = graph->adjList[v];
    while (current != NULL) {
        if (!visited[current->data]) {
            topologicalSortDFS(graph, current->data, visited, stack);
        }
        current = current->next;
    }
    push(stack, v);
}

void topologicalSort(Graph* graph) {
    Stack* stack = createStack(graph->vertices);
    bool* visited = (bool*)malloc(graph->vertices * sizeof(bool));
    for (int i = 0; i < graph->vertices; i++) {
        visited[i] = false;
    }

    for (int i = 0; i < graph->vertices; i++) {
        if (!visited[i]) {
            topologicalSortDFS(graph, i, visited, stack);
        }
    }

    printf("Output: ");
    while (!isEmpty(stack)) {
        printf("%d ", pop(stack));
    }
    printf("\n");

    free(visited);
    free(stack->array);
    free(stack);
}

int main() {
    // Example 1
    printf("Example 1: Topological Sort\n");
    int vertices1 = 4;
    Graph* graph1 = createGraph(vertices1);
    addDirectedEdge(graph1, 0, 1);
    addDirectedEdge(graph1, 0, 2);
    addDirectedEdge(graph1, 1, 3);
    addDirectedEdge(graph1, 2, 3);
    topologicalSort(graph1);
    printf("\n");

    // Example 2
    printf("Example 2: Topological Sort\n");
    int vertices2 = 6;
    Graph* graph2 = createGraph(vertices2);
    addDirectedEdge(graph2, 5, 2);
    addDirectedEdge(graph2, 5, 0);
    addDirectedEdge(graph2, 4, 0);
    addDirectedEdge(graph2, 4, 1);
    addDirectedEdge(graph2, 2, 3);
    addDirectedEdge(graph2, 3, 1);
    topologicalSort(graph2);

    return 0;
}
