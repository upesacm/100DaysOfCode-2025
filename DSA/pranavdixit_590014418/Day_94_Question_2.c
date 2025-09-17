#include <stdio.h>
#include <string.h>

int longestCommonSubsequence(char* s1, char* s2) {
    int n = strlen(s1), m = strlen(s2);
    int dp[n+1][m+1];

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            if (i == 0 || j == 0) dp[i][j] = 0;
            else if (s1[i-1] == s2[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
            else dp[i][j] = (dp[i-1][j] > dp[i][j-1]) ? dp[i-1][j] : dp[i][j-1];
        }
    }
    return dp[n][m];
}

int main() {
    char s1[] = "abcde";
    char s2[] = "ace";

    printf("%d\n", longestCommonSubsequence(s1, s2));
    return 0;
}
