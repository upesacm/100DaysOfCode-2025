#include <stdio.h>
#include <stdlib.h>

int uniquePaths(int m, int n) {
    int **dp = (int **)malloc(m * sizeof(int *));
    for (int i = 0; i < m; i++) {
        dp[i] = (int *)malloc(n * sizeof(int));
    }

    for (int i = 0; i < m; i++) dp[i][0] = 1;
    for (int j = 0; j < n; j++) dp[0][j] = 1;

    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }

    int result = dp[m - 1][n - 1];
    for (int i = 0; i < m; i++) free(dp[i]);
    free(dp);
    return result;
}

int main() {
    int m, n;
    printf("Enter grid dimensions (rows m and columns n): ");
    scanf("%d %d", &m, &n);
    printf("Total unique paths: %d\n", uniquePaths(m, n));
    return 0;
}
