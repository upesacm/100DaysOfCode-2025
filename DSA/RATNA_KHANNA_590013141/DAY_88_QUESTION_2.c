#include <stdio.h>

int n,m;
int grid[1000][1000];
int visited[1000][1000];

int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};

void dfs(int x,int y){
    visited[x][y]=1;
    for(int k=0;k<4;k++){
        int nx=x+dx[k],ny=y+dy[k];
        if(nx>=0 && nx<n && ny>=0 && ny<m && !visited[nx][ny] && grid[nx][ny]==1){
            dfs(nx,ny);
        }
    }
}

int main(){
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) scanf("%d",&grid[i][j]);
    int count=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]==1 && !visited[i][j]){
                dfs(i,j);
                count++;
            }
        }
    }
    printf("%d",count);
    return 0;
}
