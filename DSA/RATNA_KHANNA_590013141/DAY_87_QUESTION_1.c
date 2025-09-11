#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

int adj[MAX][MAX], visited[MAX], dist[MAX], queue[MAX];
int front = 0, rear = 0;

void enqueue(int x) {
    queue[rear++] = x;
}

int dequeue() {
    return queue[front++];
}

int isEmpty() {
    return front == rear;
}

int main() {
    int V, E, i, u, v, src;
    scanf("%d", &V);
    scanf("%d", &E);
    for (i = 0; i < E; i++) {
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        adj[v][u] = 1;
    }
    scanf("%d", &src);
    for (i = 0; i < V; i++) dist[i] = -1;
    visited[src] = 1;
    dist[src] = 0;
    enqueue(src);
    while (!isEmpty()) {
        int node = dequeue();
        for (i = 0; i < V; i++) {
            if (adj[node][i] && !visited[i]) {
                visited[i] = 1;
                dist[i] = dist[node] + 1;
                enqueue(i);
            }
        }
    }
    for (i = 0; i < V; i++) printf("%d ", dist[i]);
    return 0;
}
