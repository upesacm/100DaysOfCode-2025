#include <stdio.h>
#include <stdlib.h>
#define MAX 100
int V, E;
int graph[MAX][MAX];       
int transpose[MAX][MAX];  
int visited[MAX];
int stack[MAX], top = -1;
void dfs1(int v) 
{
    visited[v] = 1;
    for (int i = 0; i < V; i++) 
    {
        if (graph[v][i] && !visited[i]) 
        {
            dfs1(i);
        }
    }
    stack[++top] = v;
}
void dfs2(int v) 
{
    visited[v] = 1;
    printf("%d ", v);
    for (int i = 0; i < V; i++) 
    {
        if (transpose[v][i] && !visited[i]) 
        {
            dfs2(i);
        }
    }
}
void kosaraju() 
{
    for (int i = 0; i < V; i++)
        if (!visited[i])
            dfs1(i);
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            transpose[i][j] = graph[j][i];
    for (int i = 0; i < V; i++) visited[i] = 0;
    int sccCount = 0;
    while (top >= 0) 
    {
        int v = stack[top--];
        if (!visited[v]) 
        {
            printf("SCC %d: ", ++sccCount);
            dfs2(v);
            printf("\n");
        }
    }
    printf("\nTotal Strongly Connected Components = %d\n", sccCount);
}
int main() 
{
    printf("Enter number of vertices: ");
    scanf("%d", &V);
    printf("Enter number of edges: ");
    scanf("%d", &E);
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            graph[i][j] = 0;
    printf("Enter edges (u v) [0-indexed]:\n");
    for (int i = 0; i < E; i++) 
    {
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u][v] = 1; 
    }
    kosaraju();
    return 0;
}
