#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int visited[MAX];
int adj[MAX][MAX];
int V, E;

int dfs(int v, int parent) {
    visited[v] = 1;
    for(int u=0; u<V; u++) {
        if(adj[v][u]) {
            if(!visited[u]) {
                if(dfs(u, v)) return 1;
            } else if(u != parent) {
                return 1;
            }
        }
    }
    return 0;
}

int main() {
    scanf("%d %d", &V, &E);
    for(int i=0;i<E;i++) {
        int a,b;
        scanf("%d %d", &a, &b);
        adj[a][b] = adj[b][a] = 1;
    }
    for(int i=0;i<V;i++) {
        if(!visited[i]) {
            if(dfs(i, -1)) {
                printf("Yes\n");
                return 0;
            }
        }
    }
    printf("No\n");
    return 0;
}
