#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Structure for adjacency list node
typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

// Create new node
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

// DFS utility for cycle detection
bool dfsCycle(Graph* graph, int v, bool visited[], bool recStack[]) {
    if (!visited[v]) {
        // Mark current node as visited and add to recursion stack
        visited[v] = true;
        recStack[v] = true;

        // Recur for all neighbors
        Node* temp = graph->adjList[v];
        while (temp != NULL) {
            int adj = temp->vertex;

            if (!visited[adj] && dfsCycle(graph, adj, visited, recStack))
                return true;
            else if (recStack[adj])  // back edge found → cycle
                return true;

            temp = temp->next;
        }
    }

    // Remove vertex from recursion stack
    recStack[v] = false;
    return false;
}

// Main cycle detection function
bool containsCycle(Graph* graph) {
    bool* visited = (bool*)calloc(graph->V, sizeof(bool));
    bool* recStack = (bool*)calloc(graph->V, sizeof(bool));

    for (int i = 0; i < graph->V; i++) {
        if (!visited[i]) {
            if (dfsCycle(graph, i, visited, recStack)) {
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
    Graph* graph2 = createGraph(4);
    addEdge(graph2, 0, 1);
    addEdge(graph2, 1, 2);
    addEdge(graph2, 2, 3);

    if (containsCycle(graph2))
        printf("Yes\n");
    else
        printf("No\n");

    return 0;
}

