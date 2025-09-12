#include <stdio.h>
#include <stdbool.h>

#define V 20

int graph[V][V];
int N;

bool isSafe(int v, int path[], int pos, int visited[]) {
    if (!graph[path[pos-1]][v]) return false;
    if (visited[v]) return false;
    return true;
}

bool hamiltonianUtil(int path[], int pos, int visited[]) {
    if (pos == N) return true;  // All vertices are included

    for (int v = 0; v < N; v++) {
        if (isSafe(v, path, pos, visited)) {
            path[pos] = v;
            visited[v] = 1;
            if (hamiltonianUtil(path, pos+1, visited))
                return true;
            visited[v] = 0; // backtrack
        }
    }
    return false;
}

bool hamiltonianPath() {
    int path[V], visited[V];
    for (int i = 0; i < N; i++) visited[i] = 0;

    for (int start = 0; start < N; start++) {
        for (int i = 0; i < N; i++) {
            path[i] = -1;
            visited[i] = 0;
        }
        path[0] = start;
        visited[start] = 1;
        if (hamiltonianUtil(path, 1, visited))
            return true;
    }
    return false;
}

int main() {
    N = 4;
    int edges[][2] = {{0,1},{1,2},{2,3},{3,0}};
    int E = 4;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            graph[i][j] = 0;

    for (int i = 0; i < E; i++) {
        int u = edges[i][0], v = edges[i][1];
        graph[u][v] = graph[v][u] = 1;
    }

    if (hamiltonianPath())
        printf("Hamiltonian Path Exists\n");
    else
        printf("No Hamiltonian Path\n");

    return 0;
}

