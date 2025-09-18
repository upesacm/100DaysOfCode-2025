#include <stdio.h>
#include <stdlib.h>

int minPathSum(int **grid, int m, int n) {
    int **dp = (int **)malloc(m * sizeof(int *));
    for (int i = 0; i < m; i++) {
        dp[i] = (int *)malloc(n * sizeof(int));
    }

    dp[0][0] = grid[0][0];

    for (int i = 1; i < m; i++) dp[i][0] = dp[i - 1][0] + grid[i][0];
    for (int j = 1; j < n; j++) dp[0][j] = dp[0][j - 1] + grid[0][j];

    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            int min = dp[i - 1][j] < dp[i][j - 1] ? dp[i - 1][j] : dp[i][j - 1];
            dp[i][j] = grid[i][j] + min;
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

    int **grid = (int **)malloc(m * sizeof(int *));
    printf("Enter grid values (positive integers):\n");
    for (int i = 0; i < m; i++) {
        grid[i] = (int *)malloc(n * sizeof(int));
        for (int j = 0; j < n; j++) {
            scanf("%d", &grid[i][j]);
        }
    }

    printf("Minimum path sum: %d\n", minPathSum(grid, m, n));
    for (int i = 0; i < m; i++) free(grid[i]);
    free(grid);
    return 0;
}
