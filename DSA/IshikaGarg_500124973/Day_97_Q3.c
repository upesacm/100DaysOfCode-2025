#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

long long minll(long long a,long long b){ return a<b?a:b; }

long long matrixChainMultiplication(int p[], int n){ 
    // n = number of matrices, p length = n+1
    long long **dp = (long long**)malloc((n+1) * sizeof(long long*));
    for(int i=0;i<=n;i++){
        dp[i] = (long long*)malloc((n+1) * sizeof(long long));
        for(int j=0;j<=n;j++) dp[i][j] = 0;
    }

    for(int len=2; len<=n; ++len){ // chain length in #matrices
        for(int i=1; i<=n-len+1; ++i){
            int j = i+len-1;
            dp[i][j] = LLONG_MAX;
            for(int k=i; k<j; ++k){
                long long cost = dp[i][k] + dp[k+1][j] + (long long)p[i-1]*p[k]*p[j];
                if(cost < dp[i][j]) dp[i][j] = cost;
            }
        }
    }

    long long res = dp[1][n];
    for(int i=0;i<=n;i++) free(dp[i]);
    free(dp);
    return res;
}

int main(){
    // Example 1: dimensions [1,2,3,4] means 3 matrices: A1(1x2), A2(2x3), A3(3x4)
    int p1[] = {1,2,3,4};
    int n1 = 3;
    printf("dims [1,2,3,4] -> min cost = %lld\n", matrixChainMultiplication(p1,n1)); // expected 18

    // Example 2: [10,20,30] -> cost 6000 for single multiplication
    int p2[] = {10,20,30};
    int n2 = 2;
    printf("dims [10,20,30] -> min cost = %lld\n", matrixChainMultiplication(p2,n2)); // expected 6000

    return 0;
}

