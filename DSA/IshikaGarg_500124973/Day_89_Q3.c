#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100

int V;
int adj[MAX][MAX]; // adjacency matrix

void DFSUtil(int v, bool visited[], int adj[MAX][MAX]) {
    visited[v] = true;
    for (int i = 0; i < V; i++)
        if (adj[v][i] && !visited[i])
            DFSUtil(i, visited, adj);
}

void fillOrder(int v, bool visited[], int stack[], int *top) {
    visited[v] = true;
    for (int i = 0; i < V; i++)
        if (adj[v][i] && !visited[i])
            fillOrder(i, visited, stack, top);
    stack[++(*top)] = v;
}

void transpose(int trans[MAX][MAX]) {
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            trans[i][j] = adj[j][i];
}

int KosarajuSCC() {
    bool visited[MAX] = {false};
    int stack[MAX], top = -1;

    for (int i = 0; i < V; i++)
        if (!visited[i])
            fillOrder(i, visited, stack, &top);

    int trans[MAX][MAX];
    transpose(trans);

    for (int i = 0; i < V; i++)
        visited[i] = false;

    int scc_count = 0;
    while (top >= 0) {
        int v = stack[top--];
        if (!visited[v]) {
            DFSUtil(v, visited, trans);
            scc_count++;
        }
    }
    return scc_count;
}

int main() {
    V = 5;
    int edges[][2] = {{1,0},{0,2},{2,1},{0,3},{3,4}};
    int E = 5;

    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            adj[i][j] = 0;

    for (int i = 0; i < E; i++)
        adj[edges[i][0]][edges[i][1]] = 1;

    printf("Number of Strongly Connected Components = %d\n", KosarajuSCC());
    return 0;
}

