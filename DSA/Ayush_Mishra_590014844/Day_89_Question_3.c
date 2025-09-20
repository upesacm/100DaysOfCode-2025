#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int graph[MAX][MAX], transpose[MAX][MAX], visited[MAX], V;
int stack[MAX], top = -1;

void dfs1(int u) {
    visited[u] = 1;
    for (int v = 0; v < V; v++)
        if (graph[u][v] && !visited[v])
            dfs1(v);
    stack[++top] = u;
}

void dfs2(int u) {
    visited[u] = 1;
    for (int v = 0; v < V; v++)
        if (transpose[u][v] && !visited[v])
            dfs2(v);
}

int main() {
    int E;
    scanf("%d %d", &V, &E);
    for (int i = 0; i < E; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u][v] = 1;
    }

    for (int i = 0; i < V; i++)
        visited[i] = 0;

    for (int i = 0; i < V; i++)
        if (!visited[i])
            dfs1(i);

    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            transpose[i][j] = graph[j][i];

    for (int i = 0; i < V; i++)
        visited[i] = 0;

    int scc_count = 0;
    while (top >= 0) {
        int u = stack[top--];
        if (!visited[u]) {
            dfs2(u);
            scc_count++;
        }
    }

    printf("%d\n", scc_count);
    return 0;
}
