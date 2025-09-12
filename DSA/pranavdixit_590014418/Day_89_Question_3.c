#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int adj[MAX][MAX];
int adjT[MAX][MAX];
int visited[MAX];
int stack[MAX];
int top = -1;

void push(int v) {
    stack[++top] = v;
}
int pop() {
    return stack[top--];
}

void dfs1(int v, int V) {
    visited[v] = 1;
    for (int i = 0; i < V; i++) {
        if (adj[v][i] && !visited[i])
            dfs1(i, V);
    }
    push(v);
}

void dfs2(int v, int V) {
    visited[v] = 1;
    for (int i = 0; i < V; i++) {
        if (adjT[v][i] && !visited[i])
            dfs2(i, V);
    }
}

int kosaraju(int V) {
    for (int i = 0; i < V; i++) visited[i] = 0;
    for (int i = 0; i < V; i++)
        if (!visited[i]) dfs1(i, V);

    for (int i = 0; i < V; i++) visited[i] = 0;

    int count = 0;
    while (top != -1) {
        int v = pop();
        if (!visited[v]) {
            dfs2(v, V);
            count++;
        }
    }
    return count;
}

int main() {
    int V = 5;
    int edges[5][2] = {{1,0},{0,2},{2,1},{0,3},{3,4}};

    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            adj[i][j] = adjT[i][j] = 0;

    for (int i = 0; i < 5; i++) {
        int u = edges[i][0], v = edges[i][1];
        adj[u][v] = 1;
        adjT[v][u] = 1;
    }

    printf("Number of SCCs: %d\n", kosaraju(V));
    return 0;
}
