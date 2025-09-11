#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Structure for adjacency list node
typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

// Function to create a new adjacency list node
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
    for (int i = 0; i < V; i++) {
        graph->adjList[i] = NULL;
    }
    return graph;
}

// Add edge (undirected)
void addEdge(Graph* graph, int src, int dest) {
    Node* newNode = createNode(dest);
    newNode->next = graph->adjList[src];
    graph->adjList[src] = newNode;

    newNode = createNode(src);
    newNode->next = graph->adjList[dest];
    graph->adjList[dest] = newNode;
}

// DFS utility function for cycle detection
bool dfsCycle(Graph* graph, int v, bool visited[], int parent) {
    visited[v] = true;

    Node* temp = graph->adjList[v];
    while (temp != NULL) {
        int adj = temp->vertex;

        if (!visited[adj]) {
            if (dfsCycle(graph, adj, visited, v))
                return true;
        }
        else if (adj != parent) {
            // Found a back edge → cycle
            return true;
        }
        temp = temp->next;
    }
    return false;
}

// Main cycle detection
bool containsCycle(Graph* graph) {
    bool* visited = (bool*)calloc(graph->V, sizeof(bool));

    for (int i = 0; i < graph->V; i++) {
        if (!visited[i]) {
            if (dfsCycle(graph, i, visited, -1)) {
                free(visited);
                return true;
            }
        }
    }
    free(visited);
    return false;
}

// Driver code
int main() {
    int V = 3;
    Graph* graph = createGraph(V);

    // Example 1: Contains cycle
    addEdge(graph, 0, 1);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 0);

    if (containsCycle(graph))
        printf("Yes\n");
    else
        printf("No\n");

    // Example 2: No cycle
    Graph* graph2 = createGraph(V);
    addEdge(graph2, 0, 1);
    addEdge(graph2, 1, 2);

    if (containsCycle(graph2))
        printf("Yes\n");
    else
        printf("No\n");

    return 0;
}

