#include <stdio.h>

int graph[100][100], degree[100], n;

int main() {
    int m, u, v, odd = 0;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter number of edges: ");
    scanf("%d", &m);
    for (int i = 0; i < n; i++) {
        degree[i] = 0;
        for (int j = 0; j < n; j++)
            graph[i][j] = 0;
    }
    printf("Enter edges (u v):\n");
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);
        graph[u][v] = 1;
        graph[v][u] = 1;
        degree[u]++;
        degree[v]++;
    }
    for (int i = 0; i < n; i++)
        if (degree[i] % 2 != 0)
            odd++;
    if (odd == 0)
        printf("Eulerian Circuit Exists\n");
    else if (odd == 2)
        printf("Eulerian Path Exists\n");
    else
        printf("No Eulerian Path or Circuit\n");
    return 0;
}
