def matrixChainOrder(p: list) -> int:
    n = len(p) - 1
    dp = [[0]*n for _ in range(n)]
    for length in range(2, n+1):
        for i in range(n - length + 1):
            j = i + length - 1
            dp[i][j] = float('inf')
            for k in range(i, j):
                cost = dp[i][k] + dp[k+1][j] + p[i]*p[k+1]*p[j+1]
                dp[i][j] = min(dp[i][j], cost)
    return dp[0][n-1]

print("Input:")
p = [1, 2, 3, 4]
print("Matrix dimensions:", p)
print("Output:")
print(matrixChainOrder(p))

print("\nInput:")
p = [10, 20, 30]
print("Matrix dimensions:", p)
print("Output:")
print(matrixChainOrder(p))
