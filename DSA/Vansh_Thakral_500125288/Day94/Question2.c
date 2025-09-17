#include <stdio.h>
#include <string.h>

int max(int a, int b) { return (a > b) ? a : b; }


int LCS(char* X, char* Y) {
    int m = strlen(X), n = strlen(Y);
    int dp[m+1][n+1];

    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else if (X[i-1] == Y[j-1])
                dp[i][j] = 1 + dp[i-1][j-1];
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    return dp[m][n];
}

int main() {
    char X1[] = "abcde";
    char Y1[] = "ace";
    printf("LCS Length = %d\n", LCS(X1, Y1)); // Output: 3

    char X2[] = "abc";
    char Y2[] = "abc";
    printf("LCS Length = %d\n", LCS(X2, Y2)); // Output: 3
    return 0;
}

