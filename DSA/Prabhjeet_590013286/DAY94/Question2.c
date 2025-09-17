#include <stdio.h>
#include <string.h>

int longestCommonSubsequence(char* text1, char* text2) {
    int m = strlen(text1), n = strlen(text2);
    int dp[m+1][n+1];

    for (int i = 0; i <= m; i++)
        for (int j = 0; j <= n; j++)
            dp[i][j] = 0;

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (text1[i-1] == text2[j-1])
                dp[i][j] = dp[i-1][j-1] + 1;
            else
                dp[i][j] = dp[i-1][j] > dp[i][j-1] ? dp[i-1][j] : dp[i][j-1];
        }
    }

    return dp[m][n];
}

int main() {
    char str1[] = "abcde";
    char str2[] = "ace";
    printf("LCS Length: %d\n", longestCommonSubsequence(str1, str2));
    return 0;
}
