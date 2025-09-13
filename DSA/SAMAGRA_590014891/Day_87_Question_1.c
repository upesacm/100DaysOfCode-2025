#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

typedef struct {
    int data[MAX];
    int front, rear;
} Queue;

void initQueue(Queue *q) {
    q->front = q->rear = 0;
}

int isEmpty(Queue *q) {
    return q->front == q->rear;
}

void enqueue(Queue *q, int val) {
    q->data[q->rear++] = val;
}

int dequeue(Queue *q) {
    return q->data[q->front++];
}

void bfsShortestPath(int V, int edges[][2], int E, int src) {
    int adj[V][V];
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            adj[i][j] = 0;

    for (int i = 0; i < E; i++) {
        int u = edges[i][0], v = edges[i][1];
        adj[u][v] = adj[v][u] = 1;
    }

    int dist[V];
    for (int i = 0; i < V; i++) dist[i] = -1;

    Queue q;
    initQueue(&q);
    dist[src] = 0;
    enqueue(&q, src);

    while (!isEmpty(&q)) {
        int node = dequeue(&q);
        for (int v = 0; v < V; v++) {
            if (adj[node][v] && dist[v] == -1) {
                dist[v] = dist[node] + 1;
                enqueue(&q, v);
            }
        }
    }

    printf("Distances: ");
    for (int i = 0; i < V; i++) printf("%d ", dist[i]);
    printf("\n");
}

int main() {
    int V = 6;
    int edges[][2] = {{0,1},{0,2},{1,3},{2,4},{4,5}};
    int E = 5, src = 0;
    bfsShortestPath(V, edges, E, src);
    return 0;
}
