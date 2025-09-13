#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

bool isCyclicDirectedDFS(Graph* graph, int v, bool visited[], bool recursionStack[]) {
    visited[v] = true;
    recursionStack[v] = true;
    Node* current = graph->adjList[v];
    while (current != NULL) {
        int neighbor = current->data;
        if (!visited[neighbor]) {
            if (isCyclicDirectedDFS(graph, neighbor, visited, recursionStack)) {
                return true;
            }
        } else if (recursionStack[neighbor]) {
            return true;
        }
        current = current->next;
    }
    recursionStack[v] = false;
    return false;
}

bool detectCycleDirected(Graph* graph) {
    bool* visited = (bool*)malloc(graph->vertices * sizeof(bool));
    bool* recursionStack = (bool*)malloc(graph->vertices * sizeof(bool));
    for (int i = 0; i < graph->vertices; i++) {
        visited[i] = false;
        recursionStack[i] = false;
    }

    for (int i = 0; i < graph->vertices; i++) {
        if (!visited[i]) {
            if (isCyclicDirectedDFS(graph, i, visited, recursionStack)) {
                free(visited);
                free(recursionStack);
                return true;
            }
        }
    }
    free(visited);
    free(recursionStack);
    return false;
}

int main() {
    // Example 1
    printf("Example 1: Directed Graph with a cycle\n");
    int vertices1 = 3;
    Graph* graph1 = createGraph(vertices1);
    addDirectedEdge(graph1, 0, 1);
    addDirectedEdge(graph1, 1, 2);
    addDirectedEdge(graph1, 2, 0);
    if (detectCycleDirected(graph1)) {
        printf("Output: Yes\n\n");
    } else {
        printf("Output: No\n\n");
    }

    // Example 2
    printf("Example 2: Directed Graph without a cycle\n");
    int vertices2 = 4;
    Graph* graph2 = createGraph(vertices2);
    addDirectedEdge(graph2, 0, 1);
    addDirectedEdge(graph2, 1, 2);
    addDirectedEdge(graph2, 2, 3);
    if (detectCycleDirected(graph2)) {
        printf("Output: Yes\n\n");
    } else {
        printf("Output: No\n\n");
    }

    return 0;
}
