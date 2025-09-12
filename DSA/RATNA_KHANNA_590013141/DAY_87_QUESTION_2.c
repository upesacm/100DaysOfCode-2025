#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Node {
    int v, w;
    struct Node* next;
};

struct Graph {
    int V;
    struct Node** adj;
};

struct MinHeap {
    int size;
    int *pos, *dist, *vertex;
};

struct Node* newNode(int v, int w) {
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    n->v = v; n->w = w; n->next = NULL;
    return n;
}

struct Graph* createGraph(int V) {
    struct Graph* g = (struct Graph*)malloc(sizeof(struct Graph));
    g->V = V;
    g->adj = (struct Node**)malloc(V * sizeof(struct Node*));
    for (int i = 0; i < V; i++) g->adj[i] = NULL;
    return g;
}

void addEdge(struct Graph* g, int u, int v, int w) {
    struct Node* n = newNode(v, w);
    n->next = g->adj[u];
    g->adj[u] = n;
    n = newNode(u, w);
    n->next = g->adj[v];
    g->adj[v] = n;
}

struct MinHeap* createHeap(int V) {
    struct MinHeap* h = (struct MinHeap*)malloc(sizeof(struct MinHeap));
    h->size = V;
    h->pos = (int*)malloc(V * sizeof(int));
    h->dist = (int*)malloc(V * sizeof(int));
    h->vertex = (int*)malloc(V * sizeof(int));
    for (int i = 0; i < V; i++) {
        h->dist[i] = INT_MAX;
        h->vertex[i] = i;
        h->pos[i] = i;
    }
    return h;
}

void swapHeap(struct MinHeap* h, int i, int j) {
    int v = h->vertex[i], d = h->dist[i];
    h->vertex[i] = h->vertex[j]; h->dist[i] = h->dist[j];
    h->vertex[j] = v; h->dist[j] = d;
    h->pos[h->vertex[i]] = i;
    h->pos[h->vertex[j]] = j;
}

void heapify(struct MinHeap* h, int i) {
    int l = 2*i+1, r = 2*i+2, s = i;
    if (l < h->size && h->dist[l] < h->dist[s]) s = l;
    if (r < h->size && h->dist[r] < h->dist[s]) s = r;
    if (s != i) { swapHeap(h,i,s); heapify(h,s); }
}

int extractMin(struct MinHeap* h) {
    int root = h->vertex[0];
    h->vertex[0] = h->vertex[h->size-1];
    h->dist[0] = h->dist[h->size-1];
    h->pos[h->vertex[0]] = 0;
    h->size--;
    heapify(h,0);
    return root;
}

void decreaseKey(struct MinHeap* h, int v, int d) {
    int i = h->pos[v];
    h->dist[i] = d;
    while (i && h->dist[i] < h->dist[(i-1)/2]) {
        swapHeap(h,i,(i-1)/2);
        i = (i-1)/2;
    }
}

int inHeap(struct MinHeap* h, int v) {
    return h->pos[v] < h->size;
}

void dijkstra(struct Graph* g, int src) {
    int V = g->V;
    int dist[V];
    struct MinHeap* h = createHeap(V);
    for (int i = 0; i < V; i++) dist[i] = INT_MAX;
    dist[src] = 0;
    for (int i = 0; i < V; i++) h->dist[i] = dist[i];
    h->dist[src] = 0;
    while (h->size) {
        int u = extractMin(h);
        struct Node* p = g->adj[u];
        while (p) {
            int v = p->v;
            if (inHeap(h,v) && dist[u] != INT_MAX && dist[u]+p->w < dist[v]) {
                dist[v] = dist[u]+p->w;
                decreaseKey(h,v,dist[v]);
            }
            p = p->next;
        }
    }
    for (int i = 0; i < V; i++) printf("%d ", dist[i]);
}

int main() {
    int V,E,u,v,w,src;
    scanf("%d",&V);
    scanf("%d",&E);
    struct Graph* g = createGraph(V);
    for (int i = 0; i < E; i++) {
        scanf("%d %d %d",&u,&v,&w);
        addEdge(g,u,v,w);
    }
    scanf("%d",&src);
    dijkstra(g,src);
    return 0;
}
