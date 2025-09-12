#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Structure for a linked list node
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Structure for the graph
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

void addEdge(Graph* graph, int u, int v) {
    Node* newNode = createNode(v);
    newNode->next = graph->adjList[u];
    graph->adjList[u] = newNode;
    newNode = createNode(u);
    newNode->next = graph->adjList[v];
    graph->adjList[v] = newNode;
}

bool isCyclicDFS(Graph* graph, int v, bool visited[], int parent) {
    visited[v] = true;
    Node* current = graph->adjList[v];
    while (current != NULL) {
        int neighbor = current->data;
        if (!visited[neighbor]) {
            if (isCyclicDFS(graph, neighbor, visited, v)) {
                return true;
            }
        } else if (neighbor != parent) {
            return true;
        }
        current = current->next;
    }
    return false;
}

bool detectCycleUndirected(Graph* graph) {
    bool* visited = (bool*)malloc(graph->vertices * sizeof(bool));
    for (int i = 0; i < graph->vertices; i++) {
        visited[i] = false;
    }

    for (int i = 0; i < graph->vertices; i++) {
        if (!visited[i]) {
            if (isCyclicDFS(graph, i, visited, -1)) {
                free(visited);
                return true;
            }
        }
    }
    free(visited);
    return false;
}

int main() {
    // Example 1
    printf("Example 1: Undirected Graph with a cycle\n");
    int vertices1 = 3;
    Graph* graph1 = createGraph(vertices1);
    addEdge(graph1, 0, 1);
    addEdge(graph1, 1, 2);
    addEdge(graph1, 2, 0);
    if (detectCycleUndirected(graph1)) {
        printf("Output: Yes\n\n");
    } else {
        printf("Output: No\n\n");
    }

    // Example 2
    printf("Example 2: Undirected Graph without a cycle\n");
    int vertices2 = 3;
    Graph* graph2 = createGraph(vertices2);
    addEdge(graph2, 0, 1);
    addEdge(graph2, 1, 2);
    if (detectCycleUndirected(graph2)) {
        printf("Output: Yes\n\n");
    } else {
        printf("Output: No\n\n");
    }

    return 0;
}
