#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void dfs1(int v, bool* visited, int** graph, int* gSize, int* stack, int* top) {
    visited[v] = true;
    for (int i = 0; i < gSize[v]; i++)
        if (!visited[graph[v][i]]) dfs1(graph[v][i], visited, graph, gSize, stack, top);
    stack[(*top)++] = v;
}

void dfs2(int v, bool* visited, int** revGraph, int* revSize) {
    visited[v] = true;
    for (int i = 0; i < revSize[v]; i++)
        if (!visited[revGraph[v][i]]) dfs2(revGraph[v][i], visited, revGraph, revSize);
}

int kosarajuSCC(int V, int** graph, int* gSize, int** revGraph, int* revSize) {
    bool* visited = calloc(V, sizeof(bool));
    int* stack = malloc(V * sizeof(int));
    int top = 0;

    for (int i = 0; i < V; i++)
        if (!visited[i]) dfs1(i, visited, graph, gSize, stack, &top);

    for (int i = 0; i < V; i++) visited[i] = false;

    int scc = 0;
    for (int i = top-1; i >= 0; i--) {
        int v = stack[i];
        if (!visited[v]) {
            dfs2(v, visited, revGraph, revSize);
            scc++;
        }
    }

    free(visited); free(stack);
    return scc;
}
