#include <stdio.h>

int n,m;
int grid[100][100];
int newColor,oldColor;

void dfs(int x,int y){
    if(x<0||y<0||x>=n||y>=m||grid[x][y]!=oldColor) return;
    grid[x][y]=newColor;
    dfs(x+1,y); dfs(x-1,y); dfs(x,y+1); dfs(x,y-1);
}

int main(){
    int sr,sc;
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++) scanf("%d",&grid[i][j]);
    scanf("%d%d%d",&sr,&sc,&newColor);
    oldColor=grid[sr][sc];
    if(oldColor!=newColor) dfs(sr,sc);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++) printf("%d ",grid[i][j]);
        printf("\n");
    }
    return 0;
}
