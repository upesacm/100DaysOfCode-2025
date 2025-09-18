def unique_paths_with_obstacles(grid):
    m, n = len(grid), len(grid[0])
    
    # If start or end is blocked → no path
    if grid[0][0] == 1 or grid[m - 1][n - 1] == 1:
        return 0
    
    dp = [[0] * n for _ in range(m)]
    dp[0][0] = 1  # Start point
    
    # Fill DP table
    for i in range(m):
        for j in range(n):
            if grid[i][j] == 1:
                dp[i][j] = 0  # Blocked cell
            else:
                if i > 0:
                    dp[i][j] += dp[i - 1][j]
                if j > 0:
                    dp[i][j] += dp[i][j - 1]
    
    return dp[m - 1][n - 1]

# 🔹 Example usage
print(unique_paths_with_obstacles([[0,0,0],[0,1,0],[0,0,0]]))  # Output: 2
print(unique_paths_with_obstacles([[0,1],[0,0]]))              # Output: 1
