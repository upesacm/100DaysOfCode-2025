#include <stdio.h>
#include <stdlib.h>

struct Edge {
    int u, v, w;
};

struct Subset {
    int parent, rank;
};

int cmpEdge(const void* a, const void* b) {
    return ((struct Edge*)a)->w - ((struct Edge*)b)->w;
}

int find(struct Subset subsets[], int i) {
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
    return subsets[i].parent;
}

void unionSet(struct Subset subsets[], int x, int y) {
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);

    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;
    else {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

int kruskalMST(int V, int E, struct Edge edges[]) {
    qsort(edges, E, sizeof(edges[0]), cmpEdge);

    struct Subset* subsets = (struct Subset*) malloc(V * sizeof(struct Subset));
    for (int v = 0; v < V; v++) {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    int mstWeight = 0, e = 0;
    for (int i = 0; e < V - 1 && i < E; i++) {
        struct Edge nextEdge = edges[i];
        int x = find(subsets, nextEdge.u);
        int y = find(subsets, nextEdge.v);

        if (x != y) {
            mstWeight += nextEdge.w;
            unionSet(subsets, x, y);
            e++;
        }
    }
    free(subsets);
    return mstWeight;
}

int main() {
    int V = 4, E = 5;
    struct Edge edges[] = {
        {0, 1, 10}, {0, 2, 6}, {0, 3, 5}, {1, 3, 15}, {2, 3, 4}
    };
    printf("%d\n", kruskalMST(V, E, edges)); // Output: 19
    return 0;
}
