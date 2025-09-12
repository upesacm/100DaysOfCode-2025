#include <stdio.h>

#define V 20

int graph[V][V];
int degree[V];
int N;

void eulerianCheck() {
    int odd = 0;
    for (int i = 0; i < N; i++) {
        degree[i] = 0;
        for (int j = 0; j < N; j++)
            if (graph[i][j]) degree[i]++;
        if (degree[i] % 2 != 0) odd++;
    }

    if (odd == 0)
        printf("Eulerian Circuit Exists\n");
    else if (odd == 2)
        printf("Eulerian Path Exists\n");
    else
        printf("Neither Eulerian Path nor Circuit Exists\n");
}

int main() {
    N = 4;
    int edges[][2] = {{0,1},{1,2},{2,0},{0,3}};
    int E = 4;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            graph[i][j] = 0;

    for (int i = 0; i < E; i++) {
        int u = edges[i][0], v = edges[i][1];
        graph[u][v] = graph[v][u] = 1;
    }

    eulerianCheck();
    return 0;
}

