#include <stdio.h>
#include <stdlib.h>
#define MAX 100
struct Edge 
{
    int u, v, w;
};
int parent[MAX], rankArr[MAX];
int find(int x) 
{
    if (parent[x] != x)
        parent[x] = find(parent[x]);
    return parent[x];
}
void unionSets(int x, int y) 
{
    int rootX = find(x);
    int rootY = find(y);
    if (rootX != rootY) 
    {
        if (rankArr[rootX] < rankArr[rootY])
            parent[rootX] = rootY;
        else if (rankArr[rootX] > rankArr[rootY])
            parent[rootY] = rootX;
        else 
        {
            parent[rootY] = rootX;
            rankArr[rootX]++;
        }
    }
}
int cmpEdges(const void* a, const void* b) 
{
    return ((struct Edge*)a)->w - ((struct Edge*)b)->w;
}
int kruskal(struct Edge edges[], int V, int E) 
{
    for (int i = 0; i < V; i++) 
    {
        parent[i] = i;
        rankArr[i] = 0;
    }
    qsort(edges, E, sizeof(struct Edge), cmpEdges);
    int mstCost = 0, edgesUsed = 0;
    for (int i = 0; i < E && edgesUsed < V - 1; i++) 
    {
        int u = edges[i].u;
        int v = edges[i].v;
        int w = edges[i].w;
        if (find(u) != find(v)) 
        {
            unionSets(u, v);
            mstCost += w;
            edgesUsed++;
        }
    }
    return mstCost;
}
int main() 
{
    int V, E;
    struct Edge edges[MAX];
    printf("Enter number of vertices: ");
    scanf("%d", &V);
    printf("Enter number of edges: ");
    scanf("%d", &E);
    printf("Enter edges (u v w) [0-indexed]:\n");
    for (int i = 0; i < E; i++) 
    {
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);
    }
    int mstCost = kruskal(edges, V, E);
    printf("\nMinimum Spanning Tree Cost = %d\n", mstCost);
    return 0;
}
