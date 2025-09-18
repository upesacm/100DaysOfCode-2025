#include <stdio.h>
#include <stdlib.h>

struct Edge {
    int src, dest, weight;
};

struct Subset {
    int parent, rank;
};

int find(struct Subset* subsets, int i) {
    if (subsets[i].parent != i) {
        subsets[i].parent = find(subsets, subsets[i].parent);
    }
    return subsets[i].parent;
}

void unionSet(struct Subset* subsets, int x, int y) {
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);
    
    if (subsets[xroot].rank < subsets[yroot].rank) {
        subsets[xroot].parent = yroot;
    } else if (subsets[xroot].rank > subsets[yroot].rank) {
        subsets[yroot].parent = xroot;
    } else {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

int compareEdges(const void* a, const void* b) {
    return ((struct Edge*)a)->weight - ((struct Edge*)b)->weight;
}

int kruskalMST(struct Edge* edges, int vertices, int edgeCount) {
    struct Subset* subsets = (struct Subset*)malloc(vertices * sizeof(struct Subset));
    for (int i = 0; i < vertices; i++) {
        subsets[i].parent = i;
        subsets[i].rank = 0;
    }
    
    qsort(edges, edgeCount, sizeof(struct Edge), compareEdges);
    
    int mstWeight = 0;
    int edgeIndex = 0, edgesUsed = 0;
    
    while (edgesUsed < vertices - 1 && edgeIndex < edgeCount) {
        struct Edge nextEdge = edges[edgeIndex++];
        
        int x = find(subsets, nextEdge.src);
        int y = find(subsets, nextEdge.dest);
        
        if (x != y) {
            mstWeight += nextEdge.weight;
            unionSet(subsets, x, y);
            edgesUsed++;
        }
    }
    
    free(subsets);
    return mstWeight;
}

int main() {
    int vertices, edges;
    printf("Enter number of vertices: ");
    scanf("%d", &vertices);
    printf("Enter number of edges: ");
    scanf("%d", &edges);
    
    struct Edge* edgesArray = (struct Edge*)malloc(edges * sizeof(struct Edge));
    
    printf("Enter %d edges (u v weight):\n", edges);
    for (int i = 0; i < edges; i++) {
        scanf("%d %d %d", &edgesArray[i].src, &edgesArray[i].dest, &edgesArray[i].weight);
    }
    
    int mstWeight = kruskalMST(edgesArray, vertices, edges);
    printf("%d\n", mstWeight);
    
    free(edgesArray);
    return 0;
}
