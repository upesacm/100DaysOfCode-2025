#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int u, v, w;
} Edge;

int cmpEdge(const void* a, const void* b) {
    return ((Edge*)a)->w - ((Edge*)b)->w;
}

int find(int* parent, int x) {
    if (parent[x] != x)
        parent[x] = find(parent, parent[x]);
    return parent[x];
}

void unionSet(int* parent, int* rank, int x, int y) {
    int rx = find(parent, x);
    int ry = find(parent, y);
    if (rx != ry) {
        if (rank[rx] < rank[ry]) parent[rx] = ry;
        else if (rank[rx] > rank[ry]) parent[ry] = rx;
        else { parent[ry] = rx; rank[rx]++; }
    }
}

int kruskalMST(int V, Edge* edges, int E) {
    qsort(edges, E, sizeof(Edge), cmpEdge);

    int* parent = malloc(V * sizeof(int));
    int* rank = calloc(V, sizeof(int));
    for (int i = 0; i < V; i++) parent[i] = i;

    int cost = 0, count = 0;
    for (int i = 0; i < E && count < V - 1; i++) {
        int u = edges[i].u, v = edges[i].v, w = edges[i].w;
        if (find(parent, u) != find(parent, v)) {
            unionSet(parent, rank, u, v);
            cost += w;
            count++;
        }
    }

    free(parent); free(rank);
    return cost;
}
