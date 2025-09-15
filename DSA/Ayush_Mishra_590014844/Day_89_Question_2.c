#include <stdio.h>
#include <limits.h>

#define MAX 100

int graph[MAX][MAX], visited[MAX], key[MAX], V;

int minKey() {
    int min = INT_MAX, min_index = -1;
    for (int v = 0; v < V; v++)
        if (!visited[v] && key[v] < min) {
            min = key[v];
            min_index = v;
        }
    return min_index;
}

int main() {
    int E;
    scanf("%d %d", &V, &E);
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            graph[i][j] = 0;

    for (int i = 0; i < E; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        graph[u][v] = w;
        graph[v][u] = w;
    }

    for (int i = 0; i < V; i++) {
        key[i] = INT_MAX;
        visited[i] = 0;
    }

    key[0] = 0;
    int mst_weight = 0;

    for (int count = 0; count < V; count++) {
        int u = minKey();
        visited[u] = 1;
        mst_weight += key[u];
        for (int v = 0; v < V; v++)
            if (graph[u][v] && !visited[v] && graph[u][v] < key[v])
                key[v] = graph[u][v];
    }

    printf("%d\n", mst_weight);
    return 0;
}
