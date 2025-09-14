#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Queue {
    int* array;
    int front, rear, size, capacity;
};

struct Queue* createQueue(int capacity) {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->capacity = capacity;
    queue->front = queue->size = 0;
    queue->rear = capacity - 1;
    queue->array = (int*)malloc(capacity * sizeof(int));
    return queue;
}

int isQueueEmpty(struct Queue* queue) {
    return queue->size == 0;
}

void enqueue(struct Queue* queue, int item) {
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->array[queue->rear] = item;
    queue->size++;
}

int dequeue(struct Queue* queue) {
    int item = queue->array[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size--;
    return item;
}

void bfsShortestPath(int** adjMatrix, int vertices, int source, int* distances) {
    int* visited = (int*)calloc(vertices, sizeof(int));
    struct Queue* queue = createQueue(vertices);
    
    for (int i = 0; i < vertices; i++) {
        distances[i] = INT_MAX;
    }
    distances[source] = 0;
    visited[source] = 1;
    enqueue(queue, source);
    
    while (!isQueueEmpty(queue)) {
        int current = dequeue(queue);
        
        for (int i = 0; i < vertices; i++) {
            if (adjMatrix[current][i] && !visited[i]) {
                distances[i] = distances[current] + 1;
                visited[i] = 1;
                enqueue(queue, i);
            }
        }
    }
    
    free(visited);
    free(queue->array);
    free(queue);
}

int main() {
    int vertices, edges, source;
    printf("Enter number of vertices: ");
    scanf("%d", &vertices);
    printf("Enter number of edges: ");
    scanf("%d", &edges);
    
    int** adjMatrix = (int**)malloc(vertices * sizeof(int*));
    for (int i = 0; i < vertices; i++) {
        adjMatrix[i] = (int*)calloc(vertices, sizeof(int));
    }
    
    printf("Enter %d edges (u v):\n", edges);
    for (int i = 0; i < edges; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adjMatrix[u][v] = 1;
        adjMatrix[v][u] = 1; // Undirected graph
    }
    
    printf("Enter source vertex: ");
    scanf("%d", &source);
    
    int* distances = (int*)malloc(vertices * sizeof(int));
    bfsShortestPath(adjMatrix, vertices, source, distances);
    
    printf("Distances = [");
    for (int i = 0; i < vertices; i++) {
        if (distances[i] == INT_MAX) printf("INF");
        else printf("%d", distances[i]);
        if (i < vertices - 1) printf(",");
    }
    printf("]\n");
    
    for (int i = 0; i < vertices; i++) {
        free(adjMatrix[i]);
    }
    free(adjMatrix);
    free(distances);
    return 0;
}
