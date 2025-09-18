def unique_path_with_obstacles(obstacle_grid):
    m, n = len(obstacle_grid), len(obstacle_grid[0])

    # If start or end is blocked, no path
    if obstacle_grid[0][0] == 1 or obstacle_grid[m - 1][n - 1] == 1:
        return 0
    
    # DP table
    dp = [[0] * n for _ in range(m)]
    dp[0][0] = 1  # Start point

    # Fill DP table
    for i in range(m):
        for j in range(n):
            if obstacle_grid[i][j] == 1:
                dp[i][j] = 0  # Blocked cell
            elif i == 0 and j == 0:
                continue  # Skip start
            else:
                up = dp[i - 1][j] if i > 0 else 0
                left = dp[i][j - 1] if j > 0 else 0
                dp[i][j] = up + left

    return dp[m - 1][n - 1]

m = int(input("Enter the number of rows : "))
obstacle_grid = []
print("Enter the elements of the grid row by row, separated by spaces : ")
for _ in range(m):
    obstacle_grid.append(list(map(int, input().split())))

print(unique_path_with_obstacles(obstacle_grid))
