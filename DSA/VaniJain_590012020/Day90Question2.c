#include <stdio.h>
#include <stdlib.h>
#define MAX 100
int V, E;
int graph[MAX][MAX];
void checkEulerian() 
{
    int odd = 0;
    for (int i = 0; i < V; i++) 
    {
        int degree = 0;
        for (int j = 0; j < V; j++) 
        {
            if (graph[i][j])
                degree++;
        }
        if (degree % 2 != 0)
            odd++;
    }
    if (odd == 0)
        printf("Graph has an Eulerian Circuit.\n");
    else if (odd == 2)
        printf("Graph has an Eulerian Path (but not a Circuit).\n");
    else
        printf("Graph has neither Eulerian Path nor Circuit.\n");
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
    checkEulerian();
    return 0;
}
