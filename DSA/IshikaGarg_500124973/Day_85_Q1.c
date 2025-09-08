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

// -------- Queue --------
typedef struct {
    int* arr;
    int front, rear;
    int size;
} Queue;

Queue* createQueue(int size) {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->arr = (int*)malloc(size * sizeof(int));
    q->front = q->rear = 0;
    q->size = size;
    return q;
}

int isEmpty(Queue* q) {
    return q->front == q->rear;
}

void enqueue(Queue* q, int val) {
    q->arr[q->rear++] = val;
}

int dequeue(Queue* q) {
    return q->arr[q->front++];
}

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

    // Undirected graph
    newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = src;
    newNode->next = graph->adjList[dest];
    graph->adjList[dest] = newNode;
}

// -------- BFS --------
void BFS(Graph* graph, int start) {
    int* visited = (int*)calloc(graph->V, sizeof(int));
    Queue* q = createQueue(graph->V);

    visited[start] = 1;
    enqueue(q, start);

    while (!isEmpty(q)) {
        int v = dequeue(q);
        printf("%d ", v);

        Node* temp = graph->adjList[v];
        while (temp) {
            if (!visited[temp->vertex]) {
                visited[temp->vertex] = 1;
                enqueue(q, temp->vertex);
            }
            temp = temp->next;
        }
    }
    printf("\n");
    free(visited);
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

    printf("BFS Traversal starting from node 0:\n");
    BFS(graph, 0);

    return 0;
}

