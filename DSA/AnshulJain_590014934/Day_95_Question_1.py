m, n = map(int, input("Enter grid dimensions (m n): ").split())
dp = [[1] * n for _ in range(m)]
for i in range(1, m):
    for j in range(1, n):
        dp[i][j] = dp[i-1][j] + dp[i][j-1]
print(dp[-1][-1])
