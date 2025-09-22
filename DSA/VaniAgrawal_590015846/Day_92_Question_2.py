# Climbing Stairs
def climb_stairs(n):
    if n <= 2:
        return n
    dp = [0]*(n+1)
    dp[0], dp[1] = 1, 1
    for i in range(2, n+1):
        dp[i] = dp[i-1] + dp[i-2]
    return dp[n]

n = int(input())
print(climb_stairs(n))
