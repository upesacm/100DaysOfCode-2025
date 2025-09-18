def uniquePathsWithObstacles(grid):
    m, n = len(grid), len(grid[0])
    dp = [[0]*n for _ in range(m)]
    if grid[0][0] == 1:
        return 0
    dp[0][0] = 1
    for i in range(m):
        for j in range(n):
            if grid[i][j] == 1:
                dp[i][j] = 0
            elif i > 0 or j > 0:
                dp[i][j] = (dp[i-1][j] if i > 0 else 0) + (dp[i][j-1] if j > 0 else 0)
    return dp[m-1][n-1]

print(uniquePathsWithObstacles([[0,0,0],[0,1,0],[0,0,0]]))  # Output: 2
print(uniquePathsWithObstacles([[0,1],[0,0]]))              # Output: 1
