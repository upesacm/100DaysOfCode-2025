#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int graph[100][100], visited[100];

int main() {
    int n, m, i, j, u, v, w;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter number of edges: ");
    scanf("%d", &m);
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            graph[i][j] = 0;
    printf("Enter edges (u v weight):\n");
    for (i = 0; i < m; i++) {
        scanf("%d %d %d", &u, &v, &w);
        graph[u][v] = w;
        graph[v][u] = w;
    }
    for (i = 0; i < n; i++)
        visited[i] = 0;
    visited[0] = 1;
    int edges = 0, cost = 0;
    while (edges < n - 1) {
        int min = INT_MAX, x = -1, y = -1;
        for (i = 0; i < n; i++) {
            if (visited[i]) {
                for (j = 0; j < n; j++) {
                    if (!visited[j] && graph[i][j]) {
                        if (graph[i][j] < min) {
                            min = graph[i][j];
                            x = i;
                            y = j;
                        }
                    }
                }
            }
        }
        visited[y] = 1;
        cost += min;
        edges++;
    }
    printf("Minimum Spanning Tree Cost: %d\n", cost);
    return 0;
}
