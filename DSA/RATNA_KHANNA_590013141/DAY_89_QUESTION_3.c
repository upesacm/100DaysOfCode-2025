#include <stdio.h>
#include <stdlib.h>

int graph[100][100], transpose[100][100], visited[100], stack[100], top = -1;
int n;

void dfs1(int v) {
    visited[v] = 1;
    for (int i = 0; i < n; i++) {
        if (graph[v][i] && !visited[i])
            dfs1(i);
    }
    stack[++top] = v;
}

void dfs2(int v) {
    visited[v] = 1;
    for (int i = 0; i < n; i++) {
        if (transpose[v][i] && !visited[i])
            dfs2(i);
    }
}

int main() {
    int m, u, v, i, scc = 0;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter number of edges: ");
    scanf("%d", &m);
    for (i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            graph[i][j] = 0;
            transpose[i][j] = 0;
        }
    printf("Enter edges (u v):\n");
    for (i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);
        graph[u][v] = 1;
        transpose[v][u] = 1;
    }
    for (i = 0; i < n; i++)
        visited[i] = 0;
    for (i = 0; i < n; i++)
        if (!visited[i])
            dfs1(i);
    for (i = 0; i < n; i++)
        visited[i] = 0;
    while (top != -1) {
        int node = stack[top--];
        if (!visited[node]) {
            dfs2(node);
            scc++;
        }
    }
    printf("Total Strongly Connected Components: %d\n", scc);
    return 0;
}
