#include <stdio.h>

#define MIN(a, b) ((a) < (b) ? (a) : (b))

int main() {
    int m, n, i, j;
    printf("Enter rows and columns of grid: ");
    scanf("%d %d", &m, &n);

    int grid[m][n];
    printf("Enter the grid values:\n");
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &grid[i][j]);
        }
    }

    int dp[m][n];
    dp[0][0] = grid[0][0];

    for (j = 1; j < n; j++)
        dp[0][j] = dp[0][j - 1] + grid[0][j];

    for (i = 1; i < m; i++)
        dp[i][0] = dp[i - 1][0] + grid[i][0];

    for (i = 1; i < m; i++) {
        for (j = 1; j < n; j++) {
            dp[i][j] = grid[i][j] + MIN(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    printf("The minimum path sum is: %d\n", dp[m - 1][n - 1]);
    return 0;
}