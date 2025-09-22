#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int max(int a,int b){ return a>b?a:b; }

int longestPalindromicSubseq(char *s){
    int n = strlen(s);
    if(n==0) return 0;
    int **dp = (int**)malloc(n * sizeof(int*));
    for(int i=0;i<n;i++){
        dp[i] = (int*)calloc(n, sizeof(int));
    }

    for(int i=0;i<n;i++) dp[i][i] = 1;

    for(int len=2; len<=n; ++len){
        for(int i=0; i+len-1 < n; ++i){
            int j = i+len-1;
            if(s[i]==s[j]){
                if(i+1>j-1) dp[i][j] = 2;
                else dp[i][j] = 2 + dp[i+1][j-1];
            } else {
                dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
            }
        }
    }

    int ans = dp[0][n-1];
    for(int i=0;i<n;i++) free(dp[i]);
    free(dp);
    return ans;
}

int main(){
    char s1[] = "bbbab";
    char s2[] = "cbbd";
    printf("%s -> LPS length = %d\n", s1, longestPalindromicSubseq(s1)); // expected 4
    printf("%s -> LPS length = %d\n", s2, longestPalindromicSubseq(s2)); // expected 2
    return 0;
}
