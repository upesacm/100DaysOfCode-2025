#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 100

typedef struct {
    int items[MAX_VERTICES];
    int front, rear;
} Queue;

void initQueue(Queue* q) {
    q->front = q->rear = -1;
}

bool isEmpty(Queue* q) {
    return q->front == -1;
}

void enqueue(Queue* q, int value) {
    if (q->rear == MAX_VERTICES - 1) return;
    if (isEmpty(q)) q->front = 0;
    q->items[++q->rear] = value;
}

int dequeue(Queue* q) {
    if (isEmpty(q)) return -1;
    int value = q->items[q->front];
    if (q->front == q->rear) q->front = q->rear = -1;
    else q->front++;
    return value;
}

bool isBipartite(int vertices, int edges[][2], int edgeCount) {
    int adj[MAX_VERTICES][MAX_VERTICES] = {0};
    int color[MAX_VERTICES];
    for (int i = 0; i < vertices; i++) color[i] = -1;

    // Build adjacency matrix
    for (int i = 0; i < edgeCount; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u][v] = adj[v][u] = 1;
    }

    Queue q;
    initQueue(&q);

    for (int start = 0; start < vertices; start++) {
        if (color[start] == -1) {
            color[start] = 0;
            enqueue(&q, start);

            while (!isEmpty(&q)) {
                int u = dequeue(&q);
                for (int v = 0; v < vertices; v++) {
                    if (adj[u][v]) {
                        if (color[v] == -1) {
                            color[v] = 1 - color[u];
                            enqueue(&q, v);
                        } else if (color[v] == color[u]) {
                            return false; // Conflict detected
                        }
                    }
                }
            }
        }
    }
    return true;
}

int main() {
    int edges1[][2] = {{0,1},{1,2},{2,3},{3,0}};
    int edges2[][2] = {{0,1},{1,2},{2,0}};

    printf("Graph 1 is %s\n", isBipartite(4, edges1, 4) ? "Bipartite" : "Not Bipartite");
    printf("Graph 2 is %s\n", isBipartite(3, edges2, 3) ? "Bipartite" : "Not Bipartite");

    return 0;
}
