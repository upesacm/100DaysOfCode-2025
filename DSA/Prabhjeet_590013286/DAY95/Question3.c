int minPathSum(int** grid, int m, int n) {
    int dp[m][n];
    dp[0][0] = grid[0][0];

    // First row
    for (int j = 1; j < n; j++)
        dp[0][j] = dp[0][j-1] + grid[0][j];

    // First column
    for (int i = 1; i < m; i++)
        dp[i][0] = dp[i-1][0] + grid[i][0];

    // Fill rest of grid
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            int minPrev = (dp[i-1][j] < dp[i][j-1]) ? dp[i-1][j] : dp[i][j-1];
            dp[i][j] = grid[i][j] + minPrev;
        }
    }

    return dp[m-1][n-1];
}
