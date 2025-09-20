#include <stdio.h>

int adj[1000][1000],deg[1000];
int rev[1000][1000],rdeg[1000];
int visited[1000],order[1000],top;
int n;

void dfs1(int u){
    visited[u]=1;
    for(int i=0;i<deg[u];i++){
        int v=adj[u][i];
        if(!visited[v]) dfs1(v);
    }
    order[top++]=u;
}
void dfs2(int u){
    visited[u]=1;
    for(int i=0;i<rdeg[u];i++){
        int v=rev[u][i];
        if(!visited[v]) dfs2(v);
    }
}
int main(){
    int e,u,v;
    scanf("%d%d",&n,&e);
    for(int i=0;i<e;i++){
        scanf("%d%d",&u,&v);
        adj[u][deg[u]++]=v;
        rev[v][rdeg[v]++]=u;
    }
    for(int i=0;i<n;i++) visited[i]=0;
    top=0;
    for(int i=0;i<n;i++) if(!visited[i]) dfs1(i);
    for(int i=0;i<n;i++) visited[i]=0;
    int count=0;
    for(int i=top-1;i>=0;i--){
        int u=order[i];
        if(!visited[u]){
            dfs2(u);
            count++;
        }
    }
    printf("%d\n",count);
    return 0;
}
