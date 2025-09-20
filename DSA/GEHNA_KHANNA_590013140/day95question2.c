#include <stdio.h>
int uniquePathsWithObstacles(int** grid,int m,int n){
    int dp[m][n];
    if(grid[0][0]==1) return 0;
    dp[0][0]=1;
    for(int i=1;i<m;i++) dp[i][0]=grid[i][0]==0?dp[i-1][0]:0;
    for(int j=1;j<n;j++) dp[0][j]=grid[0][j]==0?dp[0][j-1]:0;
    for(int i=1;i<m;i++)
        for(int j=1;j<n;j++)
            dp[i][j]=grid[i][j]==0?dp[i-1][j]+dp[i][j-1]:0;
    return dp[m-1][n-1];
}
int main(){
    int m=3,n=3;
    int a[3][3]={{0,0,0},{0,1,0},{0,0,0}};
    int* grid[3];for(int i=0;i<3;i++)grid[i]=a[i];
    printf("%d\n",uniquePathsWithObstacles(grid,m,n));
    return 0;
}
