#include <stdio.h>
#include <limits.h>
#define MAX 100
#define INF INT_MAX
int graph[MAX][MAX]; 
int parent[MAX];      
int key[MAX];        
int visited[MAX];     
int V;
int minKey() 
{
    int min = INF, min_index = -1;
    for (int v = 0; v < V; v++) 
    {
        if (!visited[v] && key[v] < min) 
        {
            min = key[v];
            min_index = v;
        }
    }
    return min_index;
}
int primMST() 
{
    for (int i = 0; i < V; i++) 
    {
        key[i] = INF;
        visited[i] = 0;
    }
    key[0] = 0;    
    parent[0] = -1;
    for (int count = 0; count < V - 1; count++) 
    {
        int u = minKey();
        visited[u] = 1;
        for (int v = 0; v < V; v++) 
        {
            if (graph[u][v] && !visited[v] && graph[u][v] < key[v]) 
            {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }
    int mstCost = 0;
    for (int i = 1; i < V; i++) 
    {
        mstCost += graph[i][parent[i]];
    }
    return mstCost;
}
int main() 
{
    int E;
    printf("Enter number of vertices: ");
    scanf("%d", &V);
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            graph[i][j] = 0;
    printf("Enter number of edges: ");
    scanf("%d", &E);
    printf("Enter edges (u v w) [0-indexed]:\n");
    for (int i = 0; i < E; i++)
    {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        graph[u][v] = w;
        graph[v][u] = w; 
    }
    int mstCost = primMST();
    printf("\nMinimum Spanning Tree Cost = %d\n", mstCost);
    return 0;
}
