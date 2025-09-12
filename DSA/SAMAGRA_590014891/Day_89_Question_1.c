#include <stdio.h>
#include <stdlib.h>

struct Edge {
    int u, v, w;
};

struct Subset {
    int parent, rank;
};

int cmp(const void* a, const void* b) {
    return ((struct Edge*)a)->w - ((struct Edge*)b)->w;
}

int find(struct Subset subsets[], int i) {
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
    return subsets[i].parent;
}

void Union(struct Subset subsets[], int x, int y) {
    int xr = find(subsets, x);
    int yr = find(subsets, y);
    if (subsets[xr].rank < subsets[yr].rank)
        subsets[xr].parent = yr;
    else if (subsets[xr].rank > subsets[yr].rank)
        subsets[yr].parent = xr;
    else {
        subsets[yr].parent = xr;
        subsets[xr].rank++;
    }
}

int kruskal(int V, struct Edge edges[], int E) {
    qsort(edges, E, sizeof(edges[0]), cmp);
    struct Subset* subsets = malloc(V * sizeof(struct Subset));
    for (int v = 0; v < V; v++) {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }
    int cost = 0, e = 0, i = 0;
    while (e < V - 1 && i < E) {
        struct Edge next = edges[i++];
        int x = find(subsets, next.u);
        int y = find(subsets, next.v);
        if (x != y) {
            cost += next.w;
            Union(subsets, x, y);
            e++;
        }
    }
    free(subsets);
    return cost;
}

int main() {
    int V = 4, E = 5;
    struct Edge edges[] = {{0,1,10},{0,2,6},{0,3,5},{1,3,15},{2,3,4}};
    printf("%d\n", kruskal(V, edges, E));
    return 0;
}
