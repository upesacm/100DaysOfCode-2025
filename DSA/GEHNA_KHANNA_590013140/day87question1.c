#include <stdio.h>
#include <stdlib.h>

int q[1000], front = 0, rear = 0;
int dist[1000], visited[1000];
int adj[1000][1000], deg[1000];

void enqueue(int x){ q[rear++] = x; }
int dequeue(){ return q[front++]; }

int main(){
    int v,e,u,w,src;
    scanf("%d%d",&v,&e);
    for(int i=0;i<e;i++){
        scanf("%d%d",&u,&w);
        adj[u][deg[u]++] = w;
        adj[w][deg[w]++] = u;
    }
    scanf("%d",&src);
    for(int i=0;i<v;i++) dist[i]=-1;
    dist[src]=0; enqueue(src); visited[src]=1;
    while(front<rear){
        int node=dequeue();
        for(int i=0;i<deg[node];i++){
            int nei=adj[node][i];
            if(!visited[nei]){
                visited[nei]=1;
                dist[nei]=dist[node]+1;
                enqueue(nei);
            }
        }
    }
    for(int i=0;i<v;i++) printf("%d ",dist[i]);
    return 0;
}
