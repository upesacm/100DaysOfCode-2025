#include <stdio.h>
#include <stdlib.h>

struct Edge {
    int u, v, weight;
};

int find(int parent[], int i) {
    if (parent[i] != i)
        parent[i] = find(parent, parent[i]);
    return parent[i];
}

void unionSet(int parent[], int rank[], int x, int y) {
    int xroot = find(parent, x);
    int yroot = find(parent, y);
    if (rank[xroot] < rank[yroot])
        parent[xroot] = yroot;
    else if (rank[xroot] > rank[yroot])
        parent[yroot] = xroot;
    else {
        parent[yroot] = xroot;
        rank[xroot]++;
    }
}

int compare(const void *a, const void *b) {
    return ((struct Edge *)a)->weight - ((struct Edge *)b)->weight;
}

int main() {
    int V, E;
    scanf("%d %d", &V, &E);
    struct Edge edges[E];
    for (int i = 0; i < E; i++)
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].weight);

    qsort(edges, E, sizeof(edges[0]), compare);

    int parent[V], rank[V];
    for (int i = 0; i < V; i++) {
        parent[i] = i;
        rank[i] = 0;
    }

    int mst_weight = 0;
    for (int i = 0, count = 0; i < E && count < V - 1; i++) {
        int u = edges[i].u;
        int v = edges[i].v;
        if (find(parent, u) != find(parent, v)) {
            unionSet(parent, rank, u, v);
            mst_weight += edges[i].weight;
            count++;
        }
    }

    printf("%d\n", mst_weight);
    return 0;
}
