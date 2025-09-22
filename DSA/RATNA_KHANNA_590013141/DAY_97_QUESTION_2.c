#include <stdio.h>
#include <string.h>

int longestPalSubseq(char *s) {
    int n = strlen(s);
    int dp[n][n];

    for (int i = 0; i < n; i++) dp[i][i] = 1;

    for (int len = 2; len <= n; len++) {
        for (int i = 0; i + len - 1 < n; i++) {
            int j = i + len - 1;
            if (s[i] == s[j]) {
                if (len == 2) dp[i][j] = 2;
                else dp[i][j] = 2 + dp[i+1][j-1];
            } else {
                dp[i][j] = dp[i+1][j] > dp[i][j-1] ? dp[i+1][j] : dp[i][j-1];
            }
        }
    }

    return dp[0][n-1];
}

int main() {
    char s[1000];
    scanf("%s", s);
    printf("%d\n", longestPalSubseq(s));
    return 0;
}
