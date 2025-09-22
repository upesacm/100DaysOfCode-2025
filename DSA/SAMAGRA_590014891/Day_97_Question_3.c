#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
int min(int a,int b){return a<b?a:b;}
int main(){
    int m;
    if(scanf("%d", &m)!=1) return 0;
    if(m<2){
        printf("0\n");
        return 0;
    }
    long long *p = malloc(m * sizeof(long long));
    for(int i=0;i<m;i++) scanf("%lld", &p[i]);
    int n = m-1;
    long long **dp = malloc((n+1)*sizeof(long long*));
    for(int i=0;i<=n;i++){
        dp[i]=malloc((n+1)*sizeof(long long));
        for(int j=0;j<=n;j++) dp[i][j]=0;
    }
    for(int len=2; len<=n; len++){
        for(int i=1; i<=n-len+1; i++){
            int j = i+len-1;
            dp[i][j] = LLONG_MAX/4;
            for(int k=i; k<j; k++){
                long long cost = dp[i][k] + dp[k+1][j] + p[i-1]*p[k]*p[j];
                if(cost < dp[i][j]) dp[i][j] = cost;
            }
        }
    }
    printf("%lld\n", n?dp[1][n]:0LL);
    for(int i=0;i<=n;i++) free(dp[i]);
    free(dp);
    free(p);
    return 0;
}
