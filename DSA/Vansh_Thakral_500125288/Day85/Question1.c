#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int adj[MAX][MAX];   // adjacency matrix
int visited[MAX];
int queue[MAX], front = 0, rear = 0;

void enqueue(int x) {
    queue[rear++] = x;
}

int dequeue() {
    return queue[front++];
}

int isEmpty() {
    return front == rear;
}

void bfs(int start, int vertices) {
    enqueue(start);
    visited[start] = 1;

    while (!isEmpty()) {
        int v = dequeue();
        printf("%d ", v);

        for (int i = 0; i < vertices; i++) {
            if (adj[v][i] && !visited[i]) {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }
}

int main() {
    int vertices = 5, edges = 4;
    int edgeList[4][2] = {{0,1},{0,2},{1,3},{2,4}};

    for (int i = 0; i < edges; i++) {
        int u = edgeList[i][0], v = edgeList[i][1];
        adj[u][v] = adj[v][u] = 1;  // undirected
    }

    printf("BFS Traversal starting from node 0:\n");
    bfs(0, vertices);
    printf("\n");

    return 0;
}
