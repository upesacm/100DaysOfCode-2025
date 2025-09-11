#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define MAX 100

typedef struct {
    int vertex;
    int weight;
} Edge;

typedef struct {
    Edge edges[MAX];
    int size;
} AdjList;

AdjList graph[MAX];

void addEdge(int u, int v, int w) {
    graph[u].edges[graph[u].size++] = (Edge){v, w};
    graph[v].edges[graph[v].size++] = (Edge){u, w}; // Undirected
}

int extractMin(int dist[], bool visited[], int vertices) {
    int min = INT_MAX, minIndex = -1;
    for (int i = 0; i < vertices; i++) {
        if (!visited[i] && dist[i] < min) {
            min = dist[i];
            minIndex = i;
        }
    }
    return minIndex;
}

void dijkstra(int vertices, int source, int dist[]) {
    bool visited[MAX] = {false};

    for (int i = 0; i < vertices; i++) {
        dist[i] = INT_MAX;
    }
    dist[source] = 0;

    for (int count = 0; count < vertices - 1; count++) {
        int u = extractMin(dist, visited, vertices);
        if (u == -1) break;
        visited[u] = true;

        for (int i = 0; i < graph[u].size; i++) {
            int v = graph[u].edges[i].vertex;
            int weight = graph[u].edges[i].weight;
            if (!visited[v] && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
            }
        }
    }
}

int main() {
    int vertices = 5;
    int edges[][3] = {{0,1,2},{0,2,4},{1,2,1},{2,3,7},{1,4,3}};
    int edgeCount = sizeof(edges) / sizeof(edges[0]);
    int source = 0;
    int dist[MAX];

    for (int i = 0; i < edgeCount; i++) {
        addEdge(edges[i][0], edges[i][1], edges[i][2]);
    }

    dijkstra(vertices, source, dist);

    for (int i = 0; i < vertices; i++) {
        printf("%d ", dist[i]);
    }
    return 0;
}
