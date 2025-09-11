#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int adj[MAX][MAX];
int visited[MAX];

void dfs(int v, int vertices)
{
    visited[v] = 1;

    for (int i = 0; i < vertices; i++)
    {
        if (adj[v][i] == 1 && visited[i] == 0)
        {
            dfs(i, vertices);
        }
    }
}

int countComponents(int vertices)
{
    int count = 0;

    for (int i = 0; i < vertices; i++)
    {
        visited[i] = 0;
    }

    for (int i = 0; i < vertices; i++)
    {
        if (visited[i] == 0)
        {
            dfs(i, vertices);
            count++;
        }
    }

    return count;
}

int main()
{
    int vertices = 5;
    int edges[][2] = {{0,1},{1,2},{3,4}};
    int edgeCount = sizeof(edges) / sizeof(edges[0]);

    for (int i = 0; i < edgeCount; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    int components = countComponents(vertices);
    printf("Number of connected components: %d\n", components);  // Output: 2

    return 0;
}
