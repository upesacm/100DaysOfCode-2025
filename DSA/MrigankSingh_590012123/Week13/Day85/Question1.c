#include <stdio.h>
#include <stdlib.h>

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

void bfs(int** adjMatrix, int vertices, int start) {
    int* visited = (int*)calloc(vertices, sizeof(int));
    struct Queue* queue = createQueue(vertices);
    
    printf("%d ", start);
    visited[start] = 1;
    enqueue(queue, start);
    
    while (!isQueueEmpty(queue)) {
        int current = dequeue(queue);
        
        for (int i = 0; i < vertices; i++) {
            if (adjMatrix[current][i] && !visited[i]) {
                printf("%d ", i);
                visited[i] = 1;
                enqueue(queue, i);
            }
        }
    }
    printf("\n");
    
    free(visited);
    free(queue->array);
    free(queue);
}

int main() {
    int vertices, edges;
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
    
    printf("BFS traversal starting from vertex 0: ");
    bfs(adjMatrix, vertices, 0);
    
    for (int i = 0; i < vertices; i++) {
        free(adjMatrix[i]);
    }
    free(adjMatrix);
    return 0;
}
