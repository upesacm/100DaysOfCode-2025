def unique_paths_in_grid(m, n):
    # Initialize DP table with all 1s
    dp = [[1] * n for _ in range(m)]

    # Fill DP table
    for i in range(1, m):
        for j in range(1, n):
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1]

    # Bottom-right corner is the answer
    return dp[m - 1][n - 1]

m, n = map(int, input("Enter the rows and columns of the grid, separated by spaces : ").split())
print(unique_paths_in_grid(m, n))
