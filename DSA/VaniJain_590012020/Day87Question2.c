#include <stdio.h>
#include <limits.h>
#define MAX 100
#define INF INT_MAX
int minDistance(int dist[], int visited[], int n) 
{
    int min = INF, min_index = -1;
    for (int v = 0; v < n; v++) 
    {
        if (!visited[v] && dist[v] <= min) 
        {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}
void dijkstra(int graph[MAX][MAX], int n, int src) 
{
    int dist[MAX];      
    int visited[MAX];
    for (int i = 0; i < n; i++) 
    {
        dist[i] = INF;
        visited[i] = 0;
    }
    dist[src] = 0;
    for (int count = 0; count < n - 1; count++) 
    {
        int u = minDistance(dist, visited, n);
        if (u == -1) break; 
        visited[u] = 1;
        for (int v = 0; v < n; v++) 
        {
            if (!visited[v] && graph[u][v] && dist[u] != INF &&
                dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }
    printf("\nShortest distances from source %d:\n", src);
    for (int i = 0; i < n; i++) 
    {
        if (dist[i] == INF)
            printf("Node %d -> Distance = INF (unreachable)\n", i);
        else
            printf("Node %d -> Distance = %d\n", i, dist[i]);
    }
}
int main() 
{
    int n, e;
    int graph[MAX][MAX] = {0};
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter number of edges: ");
    scanf("%d", &e);
    printf("Enter edges (u v w) [0-indexed]:\n");
    for (int i = 0; i < e; i++) 
    {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        graph[u][v] = w;
        graph[v][u] = w; 
    }
    int src;
    printf("Enter source vertex: ");
    scanf("%d", &src);
    dijkstra(graph, n, src);
    return 0;
}
