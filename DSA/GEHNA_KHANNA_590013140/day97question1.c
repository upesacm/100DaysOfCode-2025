#include <stdio.h>
#include <string.h>
#include <limits.h>

int minCut(char *s) {
    int n = strlen(s);
    int dp[n], pal[n][n];
    for (int i = 0; i < n; i++) {
        dp[i] = 0;
        for (int j = 0; j < n; j++) pal[i][j] = 0;
    }
    for (int i = 0; i < n; i++) pal[i][i] = 1;
    for (int len = 2; len <= n; len++) {
        for (int i = 0; i + len - 1 < n; i++) {
            int j = i + len - 1;
            if (s[i] == s[j]) {
                if (len == 2 || pal[i+1][j-1]) pal[i][j] = 1;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (pal[0][i]) dp[i] = 0;
        else {
            dp[i] = INT_MAX;
            for (int j = 0; j < i; j++) {
                if (pal[j+1][i] && dp[j] + 1 < dp[i]) dp[i] = dp[j] + 1;
            }
        }
    }
    return dp[n-1];
}

int main() {
    char s[1000];
    scanf("%s", s);
    printf("%d\n", minCut(s));
    return 0;
}
