#include <stdio.h>
#include <string.h>

char words[1000][20],begin[20],end[20];
int n,visited[1000],queue[1000],dist[1000];

int diff1(char*a,char*b){
    int c=0;
    for(int i=0;a[i];i++) if(a[i]!=b[i]) c++;
    return c==1;
}
int bfs(){
    int front=0,rear=0;
    for(int i=0;i<n;i++) if(strcmp(words[i],begin)==0){visited[i]=1;queue[rear++]=i;dist[i]=1;}
    while(front<rear){
        int u=queue[front++];
        if(strcmp(words[u],end)==0) return dist[u];
        for(int v=0;v<n;v++) if(!visited[v]&&diff1(words[u],words[v])){
            visited[v]=1;
            dist[v]=dist[u]+1;
            queue[rear++]=v;
        }
    }
    return 0;
}
int main(){
    scanf("%s%s%d",begin,end,&n);
    for(int i=0;i<n;i++) scanf("%s",words[i]);
    printf("%d\n",bfs());
    return 0;
}
