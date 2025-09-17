#include <stdio.h>
#include <string.h>

int longestCommonSubsequence(char* text1, char* text2) {
    int m = strlen(text1);
    int n = strlen(text2);
    int dp[m + 1][n + 1];

    // Initialize first row and column to 0
    for (int i = 0; i <= m; i++)
        for (int j = 0; j <= n; j++)
            dp[i][j] = 0;

    // Fill the DP table
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (text1[i - 1] == text2[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;  // Match found
            else
                dp[i][j] = (dp[i - 1][j] > dp[i][j - 1]) ? dp[i - 1][j] : dp[i][j - 1];  // Max of excluding one char
        }
    }

    return dp[m][n];  // Final cell contains LCS length
}

int main() {
    char str1[] = "abcde";
    char str2[] = "ace";
    printf("LCS Length: %d\n", longestCommonSubsequence(str1, str2));  // Output: 3

    char str3[] = "abc";
    char str4[] = "abc";
    printf("LCS Length: %d\n", longestCommonSubsequence(str3, str4));  // Output: 3

    return 0;
}
