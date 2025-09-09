#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int adj[MAX][MAX];
int visited[MAX];
int stack[MAX];
int top=-1;
int V,E;

void dfs(int v) {
    visited[v] = 1;
    for(int u=0;u<V;u++) {
        if(adj[v][u] && !visited[u]) dfs(u);
    }
    stack[++top] = v;
}

int main() {
    scanf("%d %d",&V,&E);
    for(int i=0;i<E;i++) {
        int a,b;
        scanf("%d %d",&a,&b);
        adj[a][b] = 1;
    }
    for(int i=0;i<V;i++) {
        if(!visited[i]) dfs(i);
    }
    while(top>=0) {
        printf("%d ",stack[top--]);
    }
    printf("\n");
    return 0;
}
