#include <stdio.h>
#include <stdbool.h>

#define MAX 20

int V;
int graph[MAX][MAX];
bool visited[MAX];

bool hamiltonianUtil(int pos, int count) {
    if (count == V) return true; 

    for (int v = 0; v < V; v++) {
        if (graph[pos][v] && !visited[v]) {
            visited[v] = true;
            if (hamiltonianUtil(v, count + 1)) return true;
            visited[v] = false;
        }
    }
    return false;
}

bool hasHamiltonianPath() {
    for (int start = 0; start < V; start++) {
        for (int i = 0; i < V; i++) visited[i] = false;
        visited[start] = true;
        if (hamiltonianUtil(start, 1)) return true;
    }
    return false;
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