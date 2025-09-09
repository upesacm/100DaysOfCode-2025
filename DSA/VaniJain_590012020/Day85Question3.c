#include <stdio.h>
#include <stdlib.h>
#define MAX 100
int adj[MAX][MAX];
int visited[MAX];
int n;
void DFS(int node) 
{
    visited[node] = 1;
    for (int i = 0; i < n; i++) 
    {
        if (adj[node][i] && !visited[i]) 
        {
            DFS(i);
        }
    }
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
    int components = 0;
    for (int i = 0; i < n; i++) 
    {
        if (!visited[i]) 
        {
            DFS(i);
            components++;
        }
    }
    printf("Number of connected components: %d\n", components);
    return 0;
}
