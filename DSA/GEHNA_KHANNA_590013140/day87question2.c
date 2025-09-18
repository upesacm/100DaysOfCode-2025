#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int adj[1000][1000], w[1000][1000], deg[1000];
int dist[1000], visited[1000];

int extractMin(int v){
    int min=INT_MAX,idx=-1;
    for(int i=0;i<v;i++)
        if(!visited[i] && dist[i]<min){ min=dist[i]; idx=i; }
    return idx;
}

int main(){
    int v,e,u,vv,ww,src;
    scanf("%d%d",&v,&e);
    for(int i=0;i<e;i++){
        scanf("%d%d%d",&u,&vv,&ww);
        adj[u][deg[u]]=vv; w[u][deg[u]++]=ww;
        adj[vv][deg[vv]]=u; w[vv][deg[vv]++]=ww;
    }
    scanf("%d",&src);
    for(int i=0;i<v;i++) dist[i]=INT_MAX;
    dist[src]=0;
    for(int i=0;i<v;i++){
        int u=extractMin(v);
        if(u==-1) break;
        visited[u]=1;
        for(int j=0;j<deg[u];j++){
            int nei=adj[u][j],wt=w[u][j];
            if(!visited[nei] && dist[u]+wt<dist[nei])
                dist[nei]=dist[u]+wt;
        }
    }
    for(int i=0;i<v;i++) printf("%d ",dist[i]);
    return 0;
}
