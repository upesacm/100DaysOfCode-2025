#include <stdio.h>
#include <stdbool.h>

#define MAX 20

int V;
int graph[MAX][MAX];
bool visited[MAX];

bool hamiltonianUtil(int v, int count) {
    if (count == V) return true;
    for (int u = 0; u < V; u++) {
        if (graph[v][u] && !visited[u]) {
            visited[u] = true;
            if (hamiltonianUtil(u, count + 1)) return true;
            visited[u] = false;
        }
    }
    return false;
}

bool hamiltonianPath() {
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) visited[j] = false;
        visited[i] = true;
        if (hamiltonianUtil(i, 1)) return true;
    }
    return false;
}

int main() {
    int E;
    scanf("%d %d", &V, &E);
    for (int i = 0; i < E; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u][v] = graph[v][u] = 1;
    }
    if (hamiltonianPath()) printf("Yes\n");
    else printf("No\n");
    return 0;
}
