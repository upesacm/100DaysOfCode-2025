#include <stdio.h>

int graph[100][100], visited[100], n;

int backtrack(int v, int count) {
    if (count == n) return 1;
    for (int i = 0; i < n; i++) {
        if (graph[v][i] && !visited[i]) {
            visited[i] = 1;
            if (backtrack(i, count + 1)) return 1;
            visited[i] = 0;
        }
    }
    return 0;
}

int hasHamiltonianPath() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) visited[j] = 0;
        visited[i] = 1;
        if (backtrack(i, 1)) return 1;
    }
    return 0;
}

int main() {
    int m, u, v;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter number of edges: ");
    scanf("%d", &m);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            graph[i][j] = 0;
    printf("Enter edges (u v):\n");
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);
        graph[u][v] = 1;
        graph[v][u] = 1;
    }
    if (hasHamiltonianPath())
        printf("Yes\n");
    else
        printf("No\n");
    return 0;
}
