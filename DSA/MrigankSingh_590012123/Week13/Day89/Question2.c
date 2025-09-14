#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct PriorityQueue {
    int* vertices;
    int* keys;
    int size, capacity;
};

struct PriorityQueue* createPQ(int capacity) {
    struct PriorityQueue* pq = (struct PriorityQueue*)malloc(sizeof(struct PriorityQueue));
    pq->capacity = capacity;
    pq->size = 0;
    pq->vertices = (int*)malloc(capacity * sizeof(int));
    pq->keys = (int*)malloc(capacity * sizeof(int));
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
    
    if (left < pq->size && pq->keys[left] < pq->keys[smallest])
        smallest = left;
    if (right < pq->size && pq->keys[right] < pq->keys[smallest])
        smallest = right;
    
    if (smallest != i) {
        swap(&pq->vertices[i], &pq->vertices[smallest]);
        swap(&pq->keys[i], &pq->keys[smallest]);
        heapify(pq, smallest);
    }
}

void insertPQ(struct PriorityQueue* pq, int vertex, int key) {
    pq->vertices[pq->size] = vertex;
    pq->keys[pq->size] = key;
    int i = pq->size++;
    
    while (i > 0 && pq->keys[(i - 1) / 2] > pq->keys[i]) {
        swap(&pq->vertices[i], &pq->vertices[(i - 1) / 2]);
        swap(&pq->keys[i], &pq->keys[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

int extractMin(struct PriorityQueue* pq, int* vertex) {
    if (pq->size == 0) return -1;
    
    *vertex = pq->vertices[0];
    int minKey = pq->keys[0];
    
    pq->vertices[0] = pq->vertices[pq->size - 1];
    pq->keys[0] = pq->keys[pq->size - 1];
    pq->size--;
    
    heapify(pq, 0);
    return minKey;
}

int primMST(int** adjMatrix, int vertices) {
    int* key = (int*)malloc(vertices * sizeof(int));
    int* visited = (int*)calloc(vertices, sizeof(int));
    struct PriorityQueue* pq = createPQ(vertices);
    
    for (int i = 0; i < vertices; i++) {
        key[i] = INT_MAX;
    }
    key[0] = 0;
    insertPQ(pq, 0, 0);
    
    int mstWeight = 0;
    
    while (pq->size > 0) {
        int u;
        extractMin(pq, &u);
        if (visited[u]) continue;
        visited[u] = 1;
        mstWeight += key[u];
        
        for (int v = 0; v < vertices; v++) {
            if (adjMatrix[u][v] && !visited[v] && adjMatrix[u][v] < key[v]) {
                key[v] = adjMatrix[u][v];
                insertPQ(pq, v, key[v]);
            }
        }
    }
    
    free(key);
    free(visited);
    free(pq->vertices);
    free(pq->keys);
    free(pq);
    return mstWeight;
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
    
    printf("Enter %d edges (u v weight):\n", edges);
    for (int i = 0; i < edges; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        adjMatrix[u][v] = w;
        adjMatrix[v][u] = w; // Undirected graph
    }
    
    int mstWeight = primMST(adjMatrix, vertices);
    printf("%d\n", mstWeight);
    
    for (int i = 0; i < vertices; i++) {
        free(adjMatrix[i]);
    }
    free(adjMatrix);
    return 0;
}
