#include <stdio.h>
#include <limits.h>
#define MAX 100
#define INF INT_MAX
struct Edge 
{
    int u, v, w;
};
void bellmanFord(struct Edge edges[], int V, int E, int src) 
{
    int dist[MAX];
    for (int i = 0; i < V; i++) 
    {
        dist[i] = INF;
    }
    dist[src] = 0;
    for (int i = 1; i <= V - 1; i++) 
    {
        for (int j = 0; j < E; j++) 
        {
            int u = edges[j].u;
            int v = edges[j].v;
            int w = edges[j].w;

            if (dist[u] != INF && dist[u] + w < dist[v]) 
            {
                dist[v] = dist[u] + w;
            }
        }
    }
    for (int j = 0; j < E; j++) 
    {
        int u = edges[j].u;
        int v = edges[j].v;
        int w = edges[j].w;
        if (dist[u] != INF && dist[u] + w < dist[v]) 
        {
            printf("\nGraph contains negative weight cycle!\n");
            return;
        }
    }
    printf("\nShortest distances from source %d:\n", src);
    for (int i = 0; i < V; i++) 
    {
        if (dist[i] == INF)
            printf("Node %d -> Distance = INF (unreachable)\n", i);
        else
            printf("Node %d -> Distance = %d\n", i, dist[i]);
    }
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
    int src;
    printf("Enter source vertex: ");
    scanf("%d", &src);
    bellmanFord(edges, V, E, src);
    return 0;
}
