#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int max(int a, int b) {
    return a > b ? a : b;
}

int longestPalindromicSubsequence(char* s, int n) {
    // Dynamically allocate 2D DP array
    int **dp = (int **)malloc(n * sizeof(int *));
    if (dp == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    for (int i = 0; i < n; i++) {
        dp[i] = (int *)malloc(n * sizeof(int));
        if (dp[i] == NULL) {
            printf("Memory allocation failed!\n");
            exit(1);
        }
    }

    // Initialize diagonal (single characters)
    for (int i = 0; i < n; i++) {
        dp[i][i] = 1;
    }

    // Fill DP table
    for (int len = 2; len <= n; len++) {
        for (int start = 0; start <= n - len; start++) {
            int end = start + len - 1;
            if (s[start] == s[end] && len == 2) {
                dp[start][end] = 2;
            } else if (s[start] == s[end]) {
                dp[start][end] = dp[start + 1][end - 1] + 2;
            } else {
                dp[start][end] = max(dp[start + 1][end], dp[start][end - 1]);
            }
        }
    }

    int result = dp[0][n-1];

    // Free allocated memory
    for (int i = 0; i < n; i++) {
        free(dp[i]);
    }
    free(dp);

    return result;
}

int main() {
    char s[1000];
    printf("Enter the string: ");
    scanf("%s", s);

    int n = strlen(s);
    if (n == 0) {
        printf("0\n");
        return 0;
    }

    int result = longestPalindromicSubsequence(s, n);
    printf("%d\n", result);

    return 0;
}
