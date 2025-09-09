#include <stdio.h>
#include <stdlib.h>
#define MAX 100
int adj[MAX][MAX];
int visited[MAX];
int stack[MAX];
int top = -1;
int n; 
void push(int val) 
{
    stack[++top] = val;
}
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
    push(node);
}
void topologicalSort() 
{
    for (int i = 0; i < n; i++) visited[i] = 0;
    for (int i = 0; i < n; i++) 
    {
        if (!visited[i])
            DFS(i);
    }
    printf("Topological order: ");
    for (int i = top; i >= 0; i--) 
    {
        printf("%d ", stack[i]);
    }
    printf("\n");
}
int main() 
{
    int e;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter number of edges: ");
    scanf("%d", &e);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            adj[i][j] = 0;
    printf("Enter edges (u v) format (directed from u to v):\n");
    for (int i = 0; i < e; i++) 
    {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
    }
    topologicalSort();
    return 0;
}
