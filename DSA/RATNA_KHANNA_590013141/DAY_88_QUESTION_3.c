#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

int adj[MAX][MAX], color[MAX];

int bfs(int V, int src) {
    int queue[MAX], front=0, rear=0;
    queue[rear++] = src;
    color[src] = 1;
    while(front<rear) {
        int u = queue[front++];
        for(int v=0; v<V; v++) {
            if(adj[u][v]) {
                if(color[v]==-1) {
                    color[v] = 1 - color[u];
                    queue[rear++] = v;
                }
                else if(color[v]==color[u]) return 0;
            }
        }
    }
    return 1;
}

int main() {
    int V,E,u,v;
    scanf("%d",&V);
    scanf("%d",&E);
    for(int i=0;i<V;i++) color[i] = -1;
    for(int i=0;i<E;i++) {
        scanf("%d %d",&u,&v);
        adj[u][v]=1;
        adj[v][u]=1;
    }
    for(int i=0;i<V;i++) {
        if(color[i]==-1) {
            if(!bfs(V,i)) {
                printf("No");
                return 0;
            }
        }
    }
    printf("Yes");
    return 0;
}
