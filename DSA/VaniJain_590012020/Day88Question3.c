#include <stdio.h>
#include <stdlib.h>
#define MAX 100
int graph[MAX][MAX]; 
int color[MAX];    
int n, e;
int bfsCheck(int src) 
{
    int queue[MAX], front = 0, rear = 0;
    queue[rear++] = src;
    color[src] = 0; 
    while (front < rear) 
    {
        int u = queue[front++];
        for (int v = 0; v < n; v++) 
        {
            if (graph[u][v]) 
            {
                if (color[v] == -1) 
                {
                    color[v] = 1 - color[u];  
                    queue[rear++] = v;
                }
                else if (color[v] == color[u]) 
                {
                    return 0;
                }
            }
        }
    }
    return 1;
}
int isBipartite() 
{
    for (int i = 0; i < n; i++) color[i] = -1; 
    for (int i = 0; i < n; i++) 
    {
        if (color[i] == -1) 
        {
            if (!bfsCheck(i)) return 0;
        }
    }
    return 1;
}
int main() 
{
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter number of edges: ");
    scanf("%d", &e);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            graph[i][j] = 0;
    printf("Enter edges (u v) [0-indexed]:\n");
    for (int i = 0; i < e; i++) 
    {
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u][v] = 1;
        graph[v][u] = 1; 
    }
    if (isBipartite())
        printf("\nGraph is Bipartite.\n");
    else
        printf("\nGraph is NOT Bipartite.\n");
    return 0;
}
