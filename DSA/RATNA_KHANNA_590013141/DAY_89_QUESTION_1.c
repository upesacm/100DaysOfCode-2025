#include <stdio.h>
#include <stdlib.h>

struct Edge {
    int u, v, w;
};

struct Edge edges[1000];
int parent[1000];

int find(int x) {
    if (parent[x] != x)
        parent[x] = find(parent[x]);
    return parent[x];
}

void unite(int a, int b) {
    parent[find(a)] = find(b);
}

int cmp(const void* a, const void* b) {
    return ((struct Edge*)a)->w - ((struct Edge*)b)->w;
}

int main() {
    int n, m, i, cost = 0;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter number of edges: ");
    scanf("%d", &m);
    printf("Enter edges (u v weight):\n");
    for (i = 0; i < m; i++)
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);
    for (i = 0; i < n; i++)
        parent[i] = i;
    qsort(edges, m, sizeof(struct Edge), cmp);
    for (i = 0; i < m; i++) {
        if (find(edges[i].u) != find(edges[i].v)) {
            cost += edges[i].w;
            unite(edges[i].u, edges[i].v);
        }
    }
    printf("Minimum Spanning Tree Cost: %d\n", cost);
    return 0;
}
