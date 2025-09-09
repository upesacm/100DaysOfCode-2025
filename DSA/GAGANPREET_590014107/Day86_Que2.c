#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 1000

int graph[MAX][MAX];
int visited[MAX];
int recStack[MAX];
int V;

bool dfs(int v) {
    visited[v] = 1;
    recStack[v] = 1;

    for (int i = 0; i < V; i++) {
        if (graph[v][i]) {
            if (!visited[i] && dfs(i))
                return true;
            else if (recStack[i])
                return true;
        }
    }

    recStack[v] = 0;
    return false;
}

bool isCyclic() {
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (dfs(i))
                return true;
        }
    }
    return false;
}

int main() {
    int E;
    printf("Enter number of vertices: ");
    scanf("%d", &V);
    printf("Enter number of edges: ");
    scanf("%d", &E);

    for (int i = 0; i < E; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u][v] = 1;
    }

    if (isCyclic())
        printf("Yes\n");
    else
        printf("No\n");

    return 0;
}
