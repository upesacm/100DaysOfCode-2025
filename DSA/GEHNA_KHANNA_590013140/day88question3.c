#include <stdio.h>

int adj[100][100],deg[100],color[100],q[1000];

int bfs(int v){
    for(int i=0;i<v;i++) color[i]=-1;
    for(int start=0;start<v;start++){
        if(color[start]!=-1) continue;
        int front=0,rear=0;
        q[rear++]=start; color[start]=0;
        while(front<rear){
            int u=q[front++];
            for(int i=0;i<deg[u];i++){
                int nei=adj[u][i];
                if(color[nei]==-1){
                    color[nei]=1-color[u];
                    q[rear++]=nei;
                } else if(color[nei]==color[u])
                    return 0;
            }
        }
    }
    return 1;
}

int main(){
    int v,e,u,w;
    scanf("%d%d",&v,&e);
    for(int i=0;i<e;i++){
        scanf("%d%d",&u,&w);
        adj[u][deg[u]++]=w;
        adj[w][deg[w]++]=u;
    }
    if(bfs(v)) printf("Yes\n");
    else printf("No\n");
    return 0;
}
