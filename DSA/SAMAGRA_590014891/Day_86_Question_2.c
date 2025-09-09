#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int adj[MAX][MAX];
int visited[MAX];
int recStack[MAX];
int V,E;

int dfs(int v) {
    visited[v] = 1;
    recStack[v] = 1;
    for(int u=0;u<V;u++) {
        if(adj[v][u]) {
            if(!visited[u] && dfs(u)) return 1;
            else if(recStack[u]) return 1;
        }
    }
    recStack[v] = 0;
    return 0;
}

int main() {
    scanf("%d %d",&V,&E);
    for(int i=0;i<E;i++) {
        int a,b;
        scanf("%d %d",&a,&b);
        adj[a][b] = 1;
    }
    for(int i=0;i<V;i++) {
        if(!visited[i]) {
            if(dfs(i)) {
                printf("Yes\n");
                return 0;
            }
        }
    }
    printf("No\n");
    return 0;
}
