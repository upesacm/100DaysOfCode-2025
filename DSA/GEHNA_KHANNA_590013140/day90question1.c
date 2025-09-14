#include <stdio.h>

int adj[20][20],n,visited[20];

int dfs(int u,int count){
    if(count==n) return 1;
    for(int v=0;v<n;v++){
        if(adj[u][v]&&!visited[v]){
            visited[v]=1;
            if(dfs(v,count+1)) return 1;
            visited[v]=0;
        }
    }
    return 0;
}
int main(){
    int e,u,v;
    scanf("%d%d",&n,&e);
    for(int i=0;i<e;i++){scanf("%d%d",&u,&v); adj[u][v]=adj[v][u]=1;}
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++) visited[j]=0;
        visited[i]=1;
        if(dfs(i,1)){printf("Yes\n"); return 0;}
    }
    printf("No\n");
    return 0;
}
