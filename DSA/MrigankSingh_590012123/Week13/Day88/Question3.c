#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

bool isBipartite(int** adjMatrix, int vertices) {
    int* colors = (int*)malloc(vertices * sizeof(int));
    for (int i = 0; i < vertices; i++) {
        colors[i] = -1; // -1 means uncolored
    }
    
    struct Queue* queue = createQueue(vertices);
    
    for (int start = 0; start < vertices; start++) {
        if (colors[start] == -1) {
            colors[start] = 0;
            enqueue(queue, start);
            
            while (!isQueueEmpty(queue)) {
                int u = dequeue(queue);
                
                for (int v = 0; v < vertices; v++) {
                    if (adjMatrix[u][v]) {
                        if (colors[v] == -1) {
                            colors[v] = 1 - colors[u];
                            enqueue(queue, v);
                        } else if (colors[v] == colors[u]) {
                            free(colors);
                            free(queue->array);
                            free(queue);
                            return false;
                        }
                    }
                }
            }
        }
    }
    
    free(colors);
    free(queue->array);
    free(queue);
    return true;
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
    
    printf("%s\n", isBipartite(adjMatrix, vertices) ? "Yes" : "No");
    
    for (int i = 0; i < vertices; i++) {
        free(adjMatrix[i]);
    }
    free(adjMatrix);
    return 0;
}
