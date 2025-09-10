#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int adj[MAX][MAX];
int visited[MAX];
int queue[MAX];
int front = 0, rear = 0;

void enqueue(int v)
{
    queue[rear++] = v;
}

int dequeue()
{
    return queue[front++];
}

void bfs(int start, int vertices)
{
    for (int i = 0; i < vertices; i++)
    {
        visited[i] = 0;
    }

    enqueue(start);
    visited[start] = 1;

    while (front < rear)
    {
        int current = dequeue();
        printf("%d ", current);

        for (int i = 0; i < vertices; i++)
        {
            if (adj[current][i] == 1 && visited[i] == 0)
            {
                enqueue(i);
                visited[i] = 1;
            }
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

    printf("BFS Traversal starting from node 0: ");
    bfs(0, vertices);  // Output: 0 1 2 3 4
    printf("\n");

    return 0;
}
