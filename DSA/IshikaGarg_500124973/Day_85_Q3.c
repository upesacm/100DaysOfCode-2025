#include <stdio.h>
#include <stdlib.h>

// -------- Graph Node --------
typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

// -------- Graph --------
typedef struct Graph {
    int V;
    Node** adjList;
} Graph;

// -------- Graph Functions --------
Graph* createGraph(int V) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->V = V;
    graph->adjList = (Node**)malloc(V * sizeof(Node*));
    for (int i = 0; i < V; i++)
        graph->adjList[i] = NULL;
    return graph;
}

void addEdge(Graph* graph, int src, int dest) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = dest;
    newNode->next = graph->adjList[src];
    graph->adjList[src] = newNode;

    // Since undirected graph
    newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = src;
    newNode->next = graph->adjList[dest];
    graph->adjList[dest] = newNode;
}

// -------- DFS for Components --------
void DFSUtil(Graph* graph, int v, int* visited) {
    visited[v] = 1;
    Node* temp = graph->adjList[v];
    while (temp) {
        if (!visited[temp->vertex]) {
            DFSUtil(graph, temp->vertex, visited);
        }
        temp = temp->next;
    }
}

int countConnectedComponents(Graph* graph) {
    int* visited = (int*)calloc(graph->V, sizeof(int));
    int count = 0;

    for (int v = 0; v < graph->V; v++) {
        if (!visited[v]) {
            count++;
            DFSUtil(graph, v, visited);
        }
    }
    free(visited);
    return count;
}

// -------- Main --------
int main() {
    int V, E;
    printf("Enter number of vertices: ");
    scanf("%d", &V);

    Graph* graph = createGraph(V);

    printf("Enter number of edges: ");
    scanf("%d", &E);

    printf("Enter edges (u v):\n");
    for (int i = 0; i < E; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(graph, u, v);
    }

    int components = countConnectedComponents(graph);
    printf("Number of Connected Components: %d\n", components);

    return 0;
}

