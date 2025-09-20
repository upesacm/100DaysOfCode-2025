#include <stdio.h>

int main(){
    int n,e,u,v,deg[100]={0},odd=0;
    scanf("%d%d",&n,&e);
    for(int i=0;i<e;i++){scanf("%d%d",&u,&v); deg[u]++; deg[v]++;}
    for(int i=0;i<n;i++) if(deg[i]%2) odd++;
    if(odd==0) printf("Eulerian Circuit Exists\n");
    else if(odd==2) printf("Eulerian Path Exists\n");
    else printf("No Eulerian Path or Circuit\n");
    return 0;
}
