#include <stdio.h>
#include <stdlib.h>
#define MAX 20
int V, E;
int graph[MAX][MAX];
int visited[MAX];
int hamiltonianPathUtil(int v, int count) 
{
    if (count == V)   
        return 1;
    for (int i = 0; i < V; i++) 
    {
        if (graph[v][i] && !visited[i]) 
        {
            visited[i] = 1;
            if (hamiltonianPathUtil(i, count + 1))
                return 1;
            visited[i] = 0; 
        }
    }
    return 0;
}
int hamiltonianPath() 
{
    for (int start = 0; start < V; start++) 
    {
        for (int i = 0; i < V; i++) visited[i] = 0;

        visited[start] = 1;
        if (hamiltonianPathUtil(start, 1))
            return 1;
    }
    return 0;
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
        graph[v][u] = 1; 
    }
    if (hamiltonianPath())
        printf("Hamiltonian Path exists.\n");
    else
        printf("Hamiltonian Path does not exist.\n");
    return 0;
}
