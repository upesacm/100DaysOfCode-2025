#include <stdio.h>
#include <string.h>

// Function to find length of LCS using 2D DP
int longestCommonSubsequence(char *s1, char *s2) {
    int n = strlen(s1);
    int m = strlen(s2);

    int dp[n + 1][m + 1];

    // Initialize DP table with 0
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            dp[i][j] = 0;
        }
    }

    // Fill DP table
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];  // match
            } else {
                dp[i][j] = (dp[i - 1][j] > dp[i][j - 1]) ? dp[i - 1][j] : dp[i][j - 1];  // max of left/up
            }
        }
    }

    // Print DP Table
    printf("\nDP Table:\n");
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            printf("%d ", dp[i][j]);
        }
        printf("\n");
    }

    return dp[n][m]; // final answer
}

int main() {
    char s1[100], s2[100];

    printf("Enter first string: ");
    scanf("%s", s1);

    printf("Enter second string: ");
    scanf("%s", s2);

    int lcsLength = longestCommonSubsequence(s1, s2);

    printf("\nLength of Longest Common Subsequence: %d\n", lcsLength);

    return 0;
}
