#include <stdio.h>
#include <stdbool.h>

bool dfsHamiltonian(int v, int visitedCount, bool* visited, int V, int** graph, int* gSize) {
    if (visitedCount == V) return true;

    for (int i = 0; i < gSize[v]; i++) {
        int nei = graph[v][i];
        if (!visited[nei]) {
            visited[nei] = true;
            if (dfsHamiltonian(nei, visitedCount + 1, visited, V, graph, gSize)) return true;
            visited[nei] = false;
        }
    }
    return false;
}

bool hasHamiltonianPath(int V, int** graph, int* gSize) {
    bool* visited = calloc(V, sizeof(bool));
    for (int start = 0; start < V; start++) {
        visited[start] = true;
        if (dfsHamiltonian(start, 1, visited, V, graph, gSize)) {
            free(visited);
            return true;
        }
        visited[start] = false;
    }
    free(visited);
    return false;
}
