#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 100
#define INF 99999

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct Graph {
    int vertices;
    Node** adjList;
} Graph;

typedef struct Queue {
    int items[MAX_VERTICES];
    int front;
    int rear;
} Queue;

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

Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = -1;
    q->rear = -1;
    return q;
}

bool isEmpty(Queue* q) {
    return q->front == -1;
}

void enqueue(Queue* q, int value) {
    if (q->rear == MAX_VERTICES - 1) return;
    if (q->front == -1) q->front = 0;
    q->items[++q->rear] = value;
}

int dequeue(Queue* q) {
    if (isEmpty(q)) return -1;
    int item = q->items[q->front];
    q->front++;
    if (q->front > q->rear) {
        q->front = q->rear = -1;
    }
    return item;
}

void shortestPathUnweighted(Graph* graph, int source) {
    int* distances = (int*)malloc(graph->vertices * sizeof(int));
    for (int i = 0; i < graph->vertices; i++) {
        distances[i] = INF;
    }
    distances[source] = 0;

    Queue* q = createQueue();
    enqueue(q, source);

    while (!isEmpty(q)) {
        int current = dequeue(q);
        Node* temp = graph->adjList[current];
        while (temp) {
            int neighbor = temp->data;
            if (distances[neighbor] == INF) {
                distances[neighbor] = distances[current] + 1;
                enqueue(q, neighbor);
            }
            temp = temp->next;
        }
    }

    printf("Distances = [");
    for (int i = 0; i < graph->vertices; i++) {
        printf("%d", distances[i]);
        if (i < graph->vertices - 1) {
            printf(",");
        }
    }
    printf("]\n");

    free(distances);
    free(q);
}

int main() {
    printf("Example 1: Shortest Path in Unweighted Graph\n");
    int vertices1 = 6;
    Graph* graph1 = createGraph(vertices1);
    addEdge(graph1, 0, 1);
    addEdge(graph1, 0, 2);
    addEdge(graph1, 1, 3);
    addEdge(graph1, 2, 4);
    addEdge(graph1, 4, 5);
    shortestPathUnweighted(graph1, 0);
    printf("\n");

    printf("Example 2: Shortest Path in Unweighted Graph\n");
    int vertices2 = 4;
    Graph* graph2 = createGraph(vertices2);
    addEdge(graph2, 0, 1);
    addEdge(graph2, 1, 2);
    addEdge(graph2, 2, 3);
    shortestPathUnweighted(graph2, 0);

    return 0;
}
