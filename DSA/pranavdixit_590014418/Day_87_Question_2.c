#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 100
#define INF INT_MAX

int adj[MAX][MAX];
int dist[MAX];
int visited[MAX];

int minDistance(int V) {
    int min = INF, min_index = -1;
    for (int v = 0; v < V; v++) {
        if (!visited[v] && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

void dijkstra(int src, int V) {
    for (int i = 0; i < V; i++) {
        dist[i] = INF;
        visited[i] = 0;
    }
    dist[src] = 0;

    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(V);
        visited[u] = 1;

        for (int v = 0; v < V; v++) {
            if (!visited[v] && adj[u][v] && dist[u] != INF && dist[u] + adj[u][v] < dist[v]) {
                dist[v] = dist[u] + adj[u][v];
            }
        }
    }
}

int main() {
    int V = 5;
    int edges[5][3] = {{0,1,2},{0,2,4},{1,2,1},{2,3,7},{1,4,3}};

    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            adj[i][j] = 0;

    for (int i = 0; i < 5; i++) {
        int u = edges[i][0], v = edges[i][1], w = edges[i][2];
        adj[u][v] = adj[v][u] = w;
    }

    int src = 0;
    dijkstra(src, V);

    printf("Distances: ");
    for (int i = 0; i < V; i++) {
        printf("%d ", dist[i]);
    }
    printf("\n");

    return 0;
}
