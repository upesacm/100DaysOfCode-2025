#include <stdio.h>
#include <string.h>

#define MAX 999

int max(int a, int b) {
    return a > b ? a : b;
}

int longestPalindromeSubseq(char *s) {
    int n = strlen(s);
    int dp[MAX][MAX] = {0};

    for (int i = 0; i < n; i++) {
        dp[i][i] = 1;
    }

    for (int len = 2; len <= n; len++) {
        for (int i = 0; i <= n - len; i++) {
            int j = i + len - 1;
            if (s[i] == s[j]) {
                dp[i][j] = 2 + dp[i + 1][j - 1];
            } else {
                dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
            }
        }
    }

    return dp[0][n - 1];
}

int main() {
    char s[MAX];
    printf("Enter the string: ");
    scanf("%s", s);
    int result = longestPalindromeSubseq(s);
    printf("Length of longest palindromic subsequence: %d\n", result);
    return 0;
}
