#include <stdio.h>
#include <stdlib.h>
#define MAX 100
int adj[MAX][MAX];
int visited[MAX];
int n;
int DFS(int node, int parent) 
{
    visited[node] = 1;
    for (int i = 0; i < n; i++) 
    {
        if (adj[node][i]) 
        {
            if (!visited[i]) 
            {
                if (DFS(i, node)) return 1;
            } 
            else if (i != parent) 
            {
                return 1;
            }
        }
    }
    return 0;
}
int main() 
{
    int e;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter number of edges: ");
    scanf("%d", &e);
    for (int i = 0; i < n; i++) 
    {
        visited[i] = 0;
        for (int j = 0; j < n; j++) 
        {
            adj[i][j] = 0;
        }
    }
    printf("Enter edges (u v) format:\n");
    for (int i = 0; i < e; i++) 
    {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        adj[v][u] = 1;
    }
    int hasCycle = 0;
    for (int i = 0; i < n; i++) 
    {
        if (!visited[i]) 
        {
            if (DFS(i, -1)) 
            {
                hasCycle = 1;
                break;
            }
        }
    }
    if (hasCycle)
        printf("Graph contains a cycle.\n");
    else
        printf("Graph does not contain a cycle.\n");
    return 0;
}
