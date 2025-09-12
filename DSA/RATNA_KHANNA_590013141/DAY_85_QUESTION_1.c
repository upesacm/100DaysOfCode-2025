#include <stdio.h>
#include <stdlib.h>

struct Queue {
    int arr[1000];
    int front, rear;
};

void enqueue(struct Queue* q, int val) {
    q->arr[q->rear++] = val;
}

int dequeue(struct Queue* q) {
    return q->arr[q->front++];
}

int isEmpty(struct Queue* q) {
    return q->front == q->rear;
}

int main() {
    int v, e;
    printf("Enter number of vertices: ");
    scanf("%d", &v);
    printf("Enter number of edges: ");
    scanf("%d", &e);

    int adj[v][v];
    for (int i = 0; i < v; i++) {
        for (int j = 0; j < v; j++) {
            adj[i][j] = 0;
        }
    }

    printf("Enter edges (u v):\n");
    for (int i = 0; i < e; i++) {
        int u, w;
        scanf("%d %d", &u, &w);
        adj[u][w] = 1;
        adj[w][u] = 1;
    }

    int visited[v];
    for (int i = 0; i < v; i++) visited[i] = 0;

    struct Queue q;
    q.front = q.rear = 0;

    enqueue(&q, 0);
    visited[0] = 1;

    printf("BFS Traversal: ");
    while (!isEmpty(&q)) {
        int node = dequeue(&q);
        printf("%d ", node);
        for (int i = 0; i < v; i++) {
            if (adj[node][i] && !visited[i]) {
                enqueue(&q, i);
                visited[i] = 1;
            }
        }
    }
    printf("\n");
    return 0;
}
