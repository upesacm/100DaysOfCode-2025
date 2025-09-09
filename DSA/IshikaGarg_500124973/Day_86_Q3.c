#include <stdio.h>
#include <stdlib.h>

// Structure for adjacency list node
typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

// Create a new adjacency list node
Node* createNode(int v) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Graph structure
typedef struct Graph {
    int V;
    Node** adjList;
} Graph;

// Create graph
Graph* createGraph(int V) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->V = V;
    graph->adjList = (Node**)malloc(V * sizeof(Node*));
    for (int i = 0; i < V; i++)
        graph->adjList[i] = NULL;
    return graph;
}

// Add directed edge
void addEdge(Graph* graph, int src, int dest) {
    Node* newNode = createNode(dest);
    newNode->next = graph->adjList[src];
    graph->adjList[src] = newNode;
}

// DFS utility for topological sort
void dfsTopo(Graph* graph, int v, int visited[], int* stack, int* top) {
    visited[v] = 1;

    Node* temp = graph->adjList[v];
    while (temp != NULL) {
        int adj = temp->vertex;
        if (!visited[adj]) {
            dfsTopo(graph, adj, visited, stack, top);
        }
        temp = temp->next;
    }

    // push vertex onto stack after visiting all neighbors
    stack[++(*top)] = v;
}

// Topological Sort function
void topologicalSort(Graph* graph) {
    int* visited = (int*)calloc(graph->V, sizeof(int));
    int* stack = (int*)malloc(graph->V * sizeof(int));
    int top = -1;

    // Call DFS for all unvisited vertices
    for (int i = 0; i < graph->V; i++) {
        if (!visited[i]) {
            dfsTopo(graph, i, visited, stack, &top);
        }
    }

    // Print stack in reverse (finish-time order)
    while (top >= 0) {
        printf("%d ", stack[top--]);
    }
    printf("\n");

    free(visited);
    free(stack);
}

// Driver code
int main() {
    // Example 1
    int V1 = 4;
    Graph* g1 = createGraph(V1);
    addEdge(g1, 0, 1);
    addEdge(g1, 0, 2);
    addEdge(g1, 1, 3);
    addEdge(g1, 2, 3);

    printf("Topological Sort (Graph 1): ");
    topologicalSort(g1);

    // Example 2
    int V2 = 6;

