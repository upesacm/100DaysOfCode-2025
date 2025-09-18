#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int V;
int adj[MAX][MAX];
int visited[MAX];
int stack[MAX], top = -1;

void addEdge(int u, int v) {
    adj[u][v] = 1;
}

void dfs1(int v) {
    visited[v] = 1;
    for (int i = 0; i < V; i++)
        if (adj[v][i] && !visited[i])
            dfs1(i);
    stack[++top] = v;
}

void dfs2(int v, int transpose[MAX][MAX]) {
    visited[v] = 1;
    for (int i = 0; i < V; i++)
        if (transpose[v][i] && !visited[i])
            dfs2(i, transpose);
}

int kosarajuSCC() {
    for (int i = 0; i < V; i++)
        if (!visited[i])
            dfs1(i);

    int transpose[MAX][MAX] = {0};
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            if (adj[i][j])
                transpose[j][i] = 1;

    for (int i = 0; i < V; i++)
        visited[i] = 0;

    int sccCount = 0;
    while (top != -1) {
        int v = stack[top--];
        if (!visited[v]) {
            dfs2(v, transpose);
            sccCount++;
        }
    }
    return sccCount;
}

int main() {
    V = 5;
    addEdge(1,0);
    addEdge(0,2);
    addEdge(2,1);
    addEdge(0,3);
    addEdge(3,4);

    printf("%d\n", kosarajuSCC()); // Output: 3
    return 0;
}
