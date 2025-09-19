#include <stdio.h>
int min(int a,int b){return a<b?a:b;}
int minPathSum(int** grid,int m,int n){
    int dp[m][n];
    dp[0][0]=grid[0][0];
    for(int i=1;i<m;i++) dp[i][0]=dp[i-1][0]+grid[i][0];
    for(int j=1;j<n;j++) dp[0][j]=dp[0][j-1]+grid[0][j];
    for(int i=1;i<m;i++)
        for(int j=1;j<n;j++)
            dp[i][j]=grid[i][j]+min(dp[i-1][j],dp[i][j-1]);
    return dp[m-1][n-1];
}
int main(){
    int m=3,n=3;
    int a[3][3]={{1,3,1},{1,5,1},{4,2,1}};
    int* grid[3];for(int i=0;i<3;i++)grid[i]=a[i];
    printf("%d\n",minPathSum(grid,m,n));
    return 0;
}
