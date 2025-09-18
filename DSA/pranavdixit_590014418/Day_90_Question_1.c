#include <stdio.h>
#include <stdlib.h>

#define MAX 20

int graph[MAX][MAX];
int visited[MAX];
int V;

int hamiltonianUtil(int v, int count) {
    if (count == V) return 1;
    for (int u = 0; u < V; u++) {
        if (graph[v][u] && !visited[u]) {
            visited[u] = 1;
            if (hamiltonianUtil(u, count + 1)) return 1;
            visited[u] = 0;
        }
    }
    return 0;
}

int hasHamiltonianPath() {
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) visited[j] = 0;
        visited[i] = 1;
        if (hamiltonianUtil(i, 1)) return 1;
    }
    return 0;
}

int main() {
    V = 4;
    int edges[4][2] = {{0,1},{1,2},{2,3},{3,0}};
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            graph[i][j] = 0;

    for (int i = 0; i < 4; i++) {
        int u = edges[i][0], v = edges[i][1];
        graph[u][v] = graph[v][u] = 1;
    }

    if (hasHamiltonianPath()) printf("Yes\n");
    else printf("No\n");
    return 0;
}
