#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Node{int v,w; struct Node*next;};
struct Node*adj[1000];
int visited[1000],dist[1000];

void addEdge(int u,int v,int w){
    struct Node*node=(struct Node*)malloc(sizeof(struct Node));
    node->v=v;node->w=w;node->next=adj[u];adj[u]=node;
    node=(struct Node*)malloc(sizeof(struct Node));
    node->v=u;node->w=w;node->next=adj[v];adj[v]=node;
}
int main(){
    int v,e,u,w,vv;
    scanf("%d%d",&v,&e);
    for(int i=0;i<e;i++){scanf("%d%d%d",&u,&vv,&w); addEdge(u,vv,w);}
    for(int i=0;i<v;i++){dist[i]=INT_MAX; visited[i]=0;}
    dist[0]=0;
    int cost=0;
    for(int i=0;i<v;i++){
        int min=INT_MAX,u=-1;
        for(int j=0;j<v;j++) if(!visited[j]&&dist[j]<min){min=dist[j];u=j;}
        visited[u]=1; cost+=dist[u];
        for(struct Node*cur=adj[u];cur;cur=cur->next)
            if(!visited[cur->v]&&cur->w<dist[cur->v]) dist[cur->v]=cur->w;
    }
    printf("%d\n",cost);
    return 0;
}
