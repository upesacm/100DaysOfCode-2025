#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

typedef struct {
    int v, w;
} Node;

typedef struct {
    Node* data;
    int size, cap;
} MinHeap;

MinHeap* createHeap(int cap) {
    MinHeap* h = malloc(sizeof(MinHeap));
    h->data = malloc(cap * sizeof(Node));
    h->size = 0; h->cap = cap;
    return h;
}

void push(MinHeap* h, Node n) {
    int i = h->size++;
    h->data[i] = n;
    while (i && h->data[i].w < h->data[(i-1)/2].w) {
        Node t = h->data[i]; h->data[i] = h->data[(i-1)/2]; h->data[(i-1)/2] = t;
        i = (i-1)/2;
    }
}

Node pop(MinHeap* h) {
    Node root = h->data[0];
    h->data[0] = h->data[--h->size];
    int i = 0;
    while (1) {
        int l = 2*i+1, r = 2*i+2, small = i;
        if (l < h->size && h->data[l].w < h->data[small].w) small = l;
        if (r < h->size && h->data[r].w < h->data[small].w) small = r;
        if (small == i) break;
        Node t = h->data[i]; h->data[i] = h->data[small]; h->data[small] = t;
        i = small;
    }
    return root;
}

int primMST(int V, int** adj, int* adjSize) {
    bool* visited = calloc(V, sizeof(bool));
    MinHeap* h = createHeap(1000);

    push(h, (Node){0, 0});
    int cost = 0, added = 0;

    while (h->size && added < V) {
        Node cur = pop(h);
        if (visited[cur.v]) continue;
        visited[cur.v] = true;
        cost += cur.w; added++;

        for (int i = 0; i < adjSize[cur.v]; i += 2) {
            int nei = adj[cur.v][i], w = adj[cur.v][i+1];
            if (!visited[nei]) push(h, (Node){nei, w});
        }
    }

    free(visited); free(h->data); free(h);
    return cost;
}
