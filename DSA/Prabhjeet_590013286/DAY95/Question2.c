int uniquePathsWithObstacles(int** grid, int m, int n) {
    int dp[m][n];

    // Start cell
    dp[0][0] = (grid[0][0] == 0) ? 1 : 0;

    // First column
    for (int i = 1; i < m; i++)
        dp[i][0] = (grid[i][0] == 0) ? dp[i-1][0] : 0;

    // First row
    for (int j = 1; j < n; j++)
        dp[0][j] = (grid[0][j] == 0) ? dp[0][j-1] : 0;

    // Fill rest of grid
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            if (grid[i][j] == 0)
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            else
                dp[i][j] = 0;
        }
    }

    return dp[m-1][n-1];
}
