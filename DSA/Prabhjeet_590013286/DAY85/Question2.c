#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int adj[MAX][MAX];
int visited[MAX];

void dfs(int v, int vertices)
{
    visited[v] = 1;
    printf("%d ", v);

    for (int i = 0; i < vertices; i++)
    {
        if (adj[v][i] == 1 && visited[i] == 0)
        {
            dfs(i, vertices);
        }
    }
}

int main()
{
    int vertices = 5;
    int edges[][2] = {{0,1},{0,2},{1,3},{2,4}};
    int edgeCount = sizeof(edges) / sizeof(edges[0]);

    for (int i = 0; i < edgeCount; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u][v] = 1;
        adj[v][u] = 1; // Undirected graph
    }

    for (int i = 0; i < vertices; i++)
    {
        visited[i] = 0;
    }

    printf("DFS Traversal starting from node 0: ");
    dfs(0, vertices);  // Output: 0 1 3 2 4
    printf("\n");

    return 0;
}
