#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int u, v, w;
} Edge;

int cmp(const void *a, const void *b) {
    Edge *ea = (Edge *)a;
    Edge *eb = (Edge *)b;
    return ea->w - eb->w;
}

int find(int *parent, int x) {
    while (parent[x] != x) x = parent[x];
    return x;
}

void union_set(int *parent, int *rank, int a, int b) {
    int rootA = find(parent, a);
    int rootB = find(parent, b);
    if (rootA != rootB) {
        if (rank[rootA] < rank[rootB]) parent[rootA] = rootB;
        else if (rank[rootB] < rank[rootA]) parent[rootB] = rootA;
        else {
            parent[rootB] = rootA;
            rank[rootA]++;
        }
    }
}

int kruskal(Edge *edges, int E, int V) {
    int parent[V], rank[V];
    for (int i = 0; i < V; i++) {
        parent[i] = i;
        rank[i] = 0;
    }
    qsort(edges, E, sizeof(Edge), cmp);
    int mst_weight = 0, count = 0;
    for (int i = 0; i < E && count < V - 1; i++) {
        int u = edges[i].u, v = edges[i].v, w = edges[i].w;
        int rootU = find(parent, u);
        int rootV = find(parent, v);
        if (rootU != rootV) {
            union_set(parent, rank, rootU, rootV);
            mst_weight += w;
            count++;
        }
    }
    return mst_weight;
}

int main() {
    int V, E;
    scanf("%d %d", &V, &E);
    Edge edges[E];
    for (int i = 0; i < E; i++) {
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);
    }
    printf("%d\n", kruskal(edges, E, V));
    return 0;
}
