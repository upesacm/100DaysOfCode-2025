#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

// Queue implementation
typedef struct {
    int arr[MAX];
    int front, rear;
} Queue;

void initQueue(Queue *q) {
    q->front = q->rear = -1;
}

int isEmpty(Queue *q) {
    return q->front == -1;
}

void enqueue(Queue *q, int val) {
    if (q->rear == MAX - 1) return;
    if (q->front == -1) q->front = 0;
    q->arr[++q->rear] = val;
}

int dequeue(Queue *q) {
    if (isEmpty(q)) return -1;
    int val = q->arr[q->front];
    if (q->front == q->rear) q->front = q->rear = -1;
    else q->front++;
    return val;
}

// BFS Shortest Path
void bfsShortestPath(int vertices, int edges[][2], int eCount, int src) {
    int adj[vertices][vertices];
    int dist[vertices];

    // Initialize adjacency matrix and distances
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++)
            adj[i][j] = 0;
        dist[i] = -1;
    }

    // Build adjacency matrix
    for (int i = 0; i < eCount; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u][v] = adj[v][u] = 1;
    }

    Queue q;
    initQueue(&q);

    dist[src] = 0;
    enqueue(&q, src);

    while (!isEmpty(&q)) {
        int node = dequeue(&q);
        for (int v = 0; v < vertices; v++) {
            if (adj[node][v] && dist[v] == -1) {
                dist[v] = dist[node] + 1;
                enqueue(&q, v);
            }
        }
    }

    printf("Distances: ");
    for (int i = 0; i < vertices; i++)
        printf("%d ", dist[i]);
    printf("\n");
}

int main() {
    int vertices = 6;
    int edges[][2] = {{0,1},{0,2},{1,3},{2,4},{4,5}};
    int eCount = 5;
    int src = 0;

    bfsShortestPath(vertices, edges, eCount, src);
    return 0;
}

