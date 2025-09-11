#include <stdio.h>
#include <stdlib.h>

#define MAX 100


int queue[MAX], front = -1, rear = -1;

void enqueue(int value) {
    if (rear == MAX - 1) return;
    if (front == -1) front = 0;
    queue[++rear] = value;
}

int dequeue() {
    if (front == -1 || front > rear) return -1;
    return queue[front++];
}

int isEmpty() {
    return front == -1 || front > rear;
}

// BFS function
void bfs(int vertices, int graph[vertices][vertices], int start) {
    int visited[vertices];
    for (int i = 0; i < vertices; i++) visited[i] = 0;

    enqueue(start);
    visited[start] = 1;

    while (!isEmpty()) {
        int current = dequeue();
        printf("%d ", current);

        for (int i = 0; i < vertices; i++) {
            if (graph[current][i] == 1 && !visited[i]) {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }
}


int main() {
    int vertices = 5;
    int graph[5][5] = {0};

    
    graph[0][1] = graph[1][0] = 1;
    graph[0][2] = graph[2][0] = 1;
    graph[1][3] = graph[3][1] = 1;
    graph[2][4] = graph[4][2] = 1;

    printf("BFS Traversal starting from node 0:\n");
    bfs(vertices, graph, 0);

    return 0;
}
