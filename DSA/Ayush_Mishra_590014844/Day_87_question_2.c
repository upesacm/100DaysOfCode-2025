#include <stdio.h>
#include <limits.h>

#define MAX 999

int adj[MAX][MAX], dist[MAX], visited[MAX];

int minDistance(int V) {
    int min = INT_MAX, min_index = -1;
    for (int v = 0; v < V; v++) {
        if (!visited[v] && dist[v] < min) {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

int main() {
    int V, E;
    scanf("%d", &V);
    scanf("%d", &E);

    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            adj[i][j] = INT_MAX;

    for (int i = 0; i < E; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        adj[u][v] = w;
    }

    int src;
    scanf("%d", &src);

    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        visited[i] = 0;
    }

    dist[src] = 0;

    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(V);
        visited[u] = 1;

        for (int v = 0; v < V; v++) {
            if (!visited[v] && adj[u][v] != INT_MAX && dist[u] + adj[u][v] < dist[v])
                dist[v] = dist[u] + adj[u][v];
        }
    }

    for (int i = 0; i < V; i++) printf("%d ", dist[i]);
    return 0;
}
