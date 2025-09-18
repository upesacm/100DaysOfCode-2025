def minimum_path_sum(grid):
    m, n = len(grid), len(grid[0])

    # DP table same as grid (in-place optimization)
    dp = [[0] * n for _ in range(m)]

    dp[0][0] = grid[0][0]

    # Fill first row
    for j in range(1, n):
        dp[0][j] = dp[0][j - 1] + grid[0][j]

    # Fill first column
    for i in range(1, m):
        dp[i][0] = dp[i - 1][0] + grid[i][0]

    # Fill rest of the table
    for i in range(1, m):
        for j in range(1, n):
            dp[i][j] = grid[i][j] + min(dp[i - 1][j], dp[i][j - 1])

    return dp[m - 1][n - 1]

m = int(input("Enter the number of rows : "))
grid = []
print("Enter the elements of the grid row by row, separated by spaces : ")
for _ in range(m):
    grid.append(list(map(int, input().split())))

print(minimum_path_sum(grid))
