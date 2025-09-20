#include <stdio.h>
#include <string.h>

// Function to find LCS length using 2D DP
int longestCommonSubsequence(char *s1, char *s2) {
    int m = strlen(s1);
    int n = strlen(s2);

    int dp[m + 1][n + 1];

    // Initialize DP table
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else if (s1[i - 1] == s2[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = (dp[i - 1][j] > dp[i][j - 1]) ? dp[i - 1][j] : dp[i][j - 1];
        }
    }

    return dp[m][n];
}

int main() {
    char s1[] = "abcde";
    char s2[] = "ace";
    printf("LCS length: %d\n", longestCommonSubsequence(s1, s2)); // Output: 3

    char s3[] = "abc";
    char s4[] = "abc";
    printf("LCS length: %d\n", longestCommonSubsequence(s3, s4)); // Output: 3

    return 0;
}
