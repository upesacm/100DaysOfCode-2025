#include <stdio.h>
#include <stdlib.h>

struct Edge{int u,v,w;} edges[10000];
int parent[1000],rankArr[1000];

int cmp(const void*a,const void*b){
    return ((struct Edge*)a)->w - ((struct Edge*)b)->w;
}
int find(int x){
    if(parent[x]!=x) parent[x]=find(parent[x]);
    return parent[x];
}
void unite(int x,int y){
    int rx=find(x),ry=find(y);
    if(rx==ry) return;
    if(rankArr[rx]<rankArr[ry]) parent[rx]=ry;
    else if(rankArr[rx]>rankArr[ry]) parent[ry]=rx;
    else {parent[ry]=rx; rankArr[rx]++;}
}
int main(){
    int v,e;
    scanf("%d%d",&v,&e);
    for(int i=0;i<e;i++) scanf("%d%d%d",&edges[i].u,&edges[i].v,&edges[i].w);
    for(int i=0;i<v;i++){parent[i]=i; rankArr[i]=0;}
    qsort(edges,e,sizeof(edges[0]),cmp);
    int cost=0;
    for(int i=0;i<e;i++){
        int u=edges[i].u,vv=edges[i].v,w=edges[i].w;
        if(find(u)!=find(vv)){
            unite(u,vv);
            cost+=w;
        }
    }
    printf("%d\n",cost);
    return 0;
}
