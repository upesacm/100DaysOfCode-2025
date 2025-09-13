#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int V;
int graph[100][100], rev[100][100];
int visited[100], stack[100], top;

void dfs1(int v) {
    visited[v] = 1;
    for (int i = 0; i < V; i++)
        if (graph[v][i] && !visited[i]) dfs1(i);
    stack[top++] = v;
}

void dfs2(int v) {
    visited[v] = 1;
    for (int i = 0; i < V; i++)
        if (rev[v][i] && !visited[i]) dfs2(i);
}

int kosaraju() {
    memset(visited,0,sizeof(visited));
    top = 0;
    for (int i = 0; i < V; i++)
        if (!visited[i]) dfs1(i);
    memset(visited,0,sizeof(visited));
    int count = 0;
    while (top) {
        int v = stack[--top];
        if (!visited[v]) {
            dfs2(v);
            count++;
        }
    }
    return count;
}

int main() {
    V = 5;
    int edges[][2] = {{1,0},{0,2},{2,1},{0,3},{3,4}};
    int E = 5;
    for (int i=0;i<E;i++) {
        graph[edges[i][0]][edges[i][1]] = 1;
        rev[edges[i][1]][edges[i][0]] = 1;
    }
    printf("%d\n", kosaraju());
    return 0;
}
