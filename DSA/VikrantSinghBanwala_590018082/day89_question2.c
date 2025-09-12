#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct {
    int vertex, weight;
} Node;

typedef struct {
    Node *data;
    int size, capacity;
} MinHeap;

MinHeap* createHeap(int capacity) {
    MinHeap *h = (MinHeap*)malloc(sizeof(MinHeap));
    h->data = (Node*)malloc(capacity * sizeof(Node));
    h->size = 0;
    h->capacity = capacity;
    return h;
}

void swap(Node *a, Node *b) {
    Node t = *a;
    *a = *b;
    *b = t;
}

void heapifyUp(MinHeap *h, int idx) {
    while (idx && h->data[(idx-1)/2].weight > h->data[idx].weight) {
        swap(&h->data[(idx-1)/2], &h->data[idx]);
        idx = (idx-1)/2;
    }
}

void heapifyDown(MinHeap *h, int idx) {
    int smallest = idx;
    int left = 2*idx + 1;
    int right = 2*idx + 2;
    if (left < h->size && h->data[left].weight < h->data[smallest].weight) smallest = left;
    if (right < h->size && h->data[right].weight < h->data[smallest].weight) smallest = right;
    if (smallest != idx) {
        swap(&h->data[smallest], &h->data[idx]);
        heapifyDown(h, smallest);
    }
}

void push(MinHeap *h, int vertex, int weight) {
    if (h->size == h->capacity) return;
    h->data[h->size].vertex = vertex;
    h->data[h->size].weight = weight;
    heapifyUp(h, h->size);
    h->size++;
}

Node pop(MinHeap *h) {
    Node root = h->data[0];
    h->data[0] = h->data[h->size-1];
    h->size--;
    heapifyDown(h, 0);
    return root;
}

int prim(int V, int **graph) {
    int *visited = (int*)calloc(V, sizeof(int));
    MinHeap *heap = createHeap(V*V);
    push(heap, 0, 0);
    int mst_weight = 0;
    while (heap->size) {
        Node curr = pop(heap);
        int u = curr.vertex;
        if (visited[u]) continue;
        visited[u] = 1;
        mst_weight += curr.weight;
        for (int v = 0; v < V; v++) {
            if (!visited[v] && graph[u][v] != 0) {
                push(heap, v, graph[u][v]);
            }
        }
    }
    free(visited);
    free(heap->data);
    free(heap);
    return mst_weight;
}

int main() {
    int V, E;
    scanf("%d %d", &V, &E);
    int **graph = (int**)malloc(V * sizeof(int*));
    for (int i = 0; i < V; i++) {
        graph[i] = (int*)calloc(V, sizeof(int));
    }
    for (int i = 0; i < E; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        graph[u][v] = w;
        graph[v][u] = w;
    }
    printf("%d\n", prim(V, graph));
    for (int i = 0; i < V; i++) free(graph[i]);
    free(graph);
    return 0;
}
