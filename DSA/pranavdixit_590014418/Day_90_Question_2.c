#include <stdio.h>
#include <stdlib.h>

#define MAX 20

int graph[MAX][MAX];
int degree[MAX];
int V;

void computeDegree() {
    for (int i = 0; i < V; i++) {
        degree[i] = 0;
        for (int j = 0; j < V; j++) {
            if (graph[i][j]) degree[i]++;
        }
    }
}

void checkEulerian() {
    computeDegree();
    int odd = 0;
    for (int i = 0; i < V; i++) {
        if (degree[i] % 2 != 0) odd++;
    }
    if (odd == 0) printf("Eulerian Circuit Exists\n");
    else if (odd == 2) printf("Eulerian Path Exists\n");
    else printf("No Eulerian Path or Circuit\n");
}

int main() {
    V = 4;
    int edges[4][2] = {{0,1},{1,2},{2,0},{0,3}};
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            graph[i][j] = 0;

    for (int i = 0; i < 4; i++) {
        int u = edges[i][0], v = edges[i][1];
        graph[u][v] = graph[v][u] = 1;
    }

    checkEulerian();
    return 0;
}
