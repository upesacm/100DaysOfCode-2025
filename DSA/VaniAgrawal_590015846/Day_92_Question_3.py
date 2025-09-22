# Minimum Cost Climbing Stairs
def min_cost_climbing_stairs(cost):
    n = len(cost)
    dp = [0]*(n+1)
    for i in range(2, n+1):
        dp[i] = min(dp[i-1] + cost[i-1], dp[i-2] + cost[i-2])
    return dp[n]

cost = list(map(int, input().split()))
print(min_cost_climbing_stairs(cost))
