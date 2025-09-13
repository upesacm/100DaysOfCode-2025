#include <stdio.h>
#include <stdlib.h>

int isHamiltonian(int **graph, int *visited, int v, int n, int count) {
    if (count == n) return 1;
    for (int i = 0; i < n; i++) {
        if (graph[v][i] && !visited[i]) {
            visited[i] = 1;
            if (isHamiltonian(graph, visited, i, n, count + 1)) return 1;
            visited[i] = 0;
        }
    }
    return 0;
}

int main() {
    int n, e;
    scanf("%d %d", &n, &e);
    int **graph = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        graph[i] = (int *)calloc(n, sizeof(int));
    }
    for (int i = 0; i < e; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u][v] = graph[v][u] = 1;
    }
    int *visited = (int *)calloc(n, sizeof(int));
    int exists = 0;
    for (int i = 0; i < n; i++) {
        visited[i] = 1;
        if (isHamiltonian(graph, visited, i, n, 1)) {
            exists = 1;
            break;
        }
        visited[i] = 0;
    }
    printf("%s\n", exists ? "Yes" : "No");
    for (int i = 0; i < n; i++) free(graph[i]);
    free(graph);
    free(visited);
    return 0;
}
