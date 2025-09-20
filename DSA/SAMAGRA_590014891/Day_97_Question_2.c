#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int max(int a,int b){return a>b?a:b;}
int main(){
    char s[2005];
    if(scanf("%2000s", s)!=1) return 0;
    int n = strlen(s);
    int **dp = malloc(n * sizeof(int*));
    for(int i=0;i<n;i++){
        dp[i]=calloc(n,sizeof(int));
    }
    for(int i=n-1;i>=0;i--){
        dp[i][i]=1;
        for(int j=i+1;j<n;j++){
            if(s[i]==s[j]) dp[i][j] = dp[i+1][j-1] + 2;
            else dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
            if(j==i+1 && s[i]==s[j]) dp[i][j]=2;
        }
    }
    printf("%d\n", n?dp[0][n-1]:0);
    for(int i=0;i<n;i++) free(dp[i]);
    free(dp);
    return 0;
}
