#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct PriorityQueue {
    int* vertices;
    int* distances;
    int size, capacity;
};

struct PriorityQueue* createPQ(int capacity) {
    struct PriorityQueue* pq = (struct PriorityQueue*)malloc(sizeof(struct PriorityQueue));
    pq->capacity = capacity;
    pq->size = 0;
    pq->vertices = (int*)malloc(capacity * sizeof(int));
    pq->distances = (int*)malloc(capacity * sizeof(int));
    return pq;
}

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(struct PriorityQueue* pq, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    
    if (left < pq->size && pq->distances[left] < pq->distances[smallest])
        smallest = left;
    if (right < pq->size && pq->distances[right] < pq->distances[smallest])
        smallest = right;
    
    if (smallest != i) {
        swap(&pq->vertices[i], &pq->vertices[smallest]);
        swap(&pq->distances[i], &pq->distances[smallest]);
        heapify(pq, smallest);
    }
}

void insertPQ(struct PriorityQueue* pq, int vertex, int distance) {
    pq->vertices[pq->size] = vertex;
    pq->distances[pq->size] = distance;
    int i = pq->size++;
    
    while (i > 0 && pq->distances[(i - 1) / 2] > pq->distances[i]) {
        swap(&pq->vertices[i], &pq->vertices[(i - 1) / 2]);
        swap(&pq->distances[i], &pq->distances[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

int extractMin(struct PriorityQueue* pq, int* vertex) {
    if (pq->size == 0) return -1;
    
    *vertex = pq->vertices[0];
    int minDistance = pq->distances[0];
    
    pq->vertices[0] = pq->vertices[pq->size - 1];
    pq->distances[0] = pq->distances[pq->size - 1];
    pq->size--;
    
    heapify(pq, 0);
    return minDistance;
}

void dijkstra(int** adjMatrix, int vertices, int source, int* distances) {
    struct PriorityQueue* pq = createPQ(vertices);
    int* visited = (int*)calloc(vertices, sizeof(int));
    
    for (int i = 0; i < vertices; i++) {
        distances[i] = INT_MAX;
    }
    distances[source] = 0;
    insertPQ(pq, source, 0);
    
    while (pq->size > 0) {
        int u;
        extractMin(pq, &u);
        if (visited[u]) continue;
        visited[u] = 1;
        
        for (int v = 0; v < vertices; v++) {
            if (adjMatrix[u][v] && !visited[v] && distances[u] != INT_MAX) {
                if (distances[u] + adjMatrix[u][v] < distances[v]) {
                    distances[v] = distances[u] + adjMatrix[u][v];
                    insertPQ(pq, v, distances[v]);
                }
            }
        }
    }
    
    free(pq->vertices);
    free(pq->distances);
    free(pq);
    free(visited);
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
    
    printf("Enter %d edges (u v weight):\n", edges);
    for (int i = 0; i < edges; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        adjMatrix[u][v] = w;
        adjMatrix[v][u] = w; // Undirected graph
    }
    
    printf("Enter source vertex: ");
    scanf("%d", &source);
    
    int* distances = (int*)malloc(vertices * sizeof(int));
    dijkstra(adjMatrix, vertices, source, distances);
    
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
