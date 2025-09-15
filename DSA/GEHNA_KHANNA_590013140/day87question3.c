#include <stdio.h>
#include <limits.h>

struct Edge{ int u,v,w; } edges[10000];
int dist[1000];

int main(){
    int v,e,src;
    scanf("%d%d",&v,&e);
    for(int i=0;i<e;i++) scanf("%d%d%d",&edges[i].u,&edges[i].v,&edges[i].w);
    scanf("%d",&src);
    for(int i=0;i<v;i++) dist[i]=INT_MAX;
    dist[src]=0;
    for(int i=0;i<v-1;i++)
        for(int j=0;j<e;j++){
            int u=edges[j].u,vv=edges[j].v,wt=edges[j].w;
            if(dist[u]!=INT_MAX && dist[u]+wt<dist[vv])
                dist[vv]=dist[u]+wt;
        }
    for(int j=0;j<e;j++){
        int u=edges[j].u,vv=edges[j].v,wt=edges[j].w;
        if(dist[u]!=INT_MAX && dist[u]+wt<dist[vv]){
            printf("Negative cycle\n");
            return 0;
        }
    }
    for(int i=0;i<v;i++) printf("%d ",dist[i]);
    return 0;
}
