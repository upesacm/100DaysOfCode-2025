#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int adj[MAX][MAX];
int dist[MAX];
int visited[MAX];
int queue[MAX];
int front = 0, rear = 0;

void enqueue(int v) {
    queue[rear++] = v;
}
int dequeue() {
    return queue[front++];
}
int isEmpty() {
    return front == rear;
}

void bfsShortestPath(int src, int V) {
    for (int i = 0; i < V; i++) {
        dist[i] = -1;
        visited[i] = 0;
    }
    dist[src] = 0;
    visited[src] = 1;
    enqueue(src);

    while (!isEmpty()) {
        int u = dequeue();
        for (int v = 0; v < V; v++) {
            if (adj[u][v] && !visited[v]) {
                visited[v] = 1;
                dist[v] = dist[u] + 1;
                enqueue(v);
            }
        }
    }
}

int main() {
    int V = 6;
    int edges[5][2] = {{0,1},{0,2},{1,3},{2,4},{4,5}};

    for (int i = 0; i < 5; i++) {
        int u = edges[i][0], v = edges[i][1];
        adj[u][v] = adj[v][u] = 1;
    }

    int src = 0;
    bfsShortestPath(src, V);

    printf("Distances: ");
    for (int i = 0; i < V; i++) {
        printf("%d ", dist[i]);
    }
    printf("\n");

    return 0;
}
