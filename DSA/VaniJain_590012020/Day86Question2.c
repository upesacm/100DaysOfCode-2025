#include <stdio.h>
#include <stdlib.h>
#define MAX 100
int adj[MAX][MAX];
int visited[MAX];
int recStack[MAX];
int n; 
int DFS(int node) 
{
    visited[node] = 1;
    recStack[node] = 1;
    for (int i = 0; i < n; i++) 
    {
        if (adj[node][i]) 
        {
            if (!visited[i] && DFS(i))
                return 1;
            else if (recStack[i])
                return 1; 
        }
    }
    recStack[node] = 0; 
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
        recStack[i] = 0;
        for (int j = 0; j < n; j++)
            adj[i][j] = 0;
    }
    printf("Enter edges (u v) format (directed from u to v):\n");
    for (int i = 0; i < e; i++) 
    {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
    }
    int hasCycle = 0;
    for (int i = 0; i < n; i++) 
    {
        if (!visited[i]) 
        {
            if (DFS(i)) 
            {
                hasCycle = 1;
                break;
            }
        }
    if (hasCycle)
        printf("Directed graph contains a cycle.\n");
    else
        printf("Directed graph does not contain a cycle.\n");
    return 0;
}
