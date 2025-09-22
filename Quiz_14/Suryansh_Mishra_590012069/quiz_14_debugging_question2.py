def knapsack_01(weights, values, capacity):
    n = len(weights)
    # dp[i][w] = max value using first i items within capacity w
    dp = [[0] * (capacity + 1) for _ in range(n + 1)]

    for i in range(1, n + 1):
        wi, vi = weights[i - 1], values[i - 1]  # correct indices
        for w in range(0, capacity + 1):
            # exclude item i
            dp[i][w] = dp[i - 1][w]
            # include item i if it fits
            if wi <= w:
                dp[i][w] = max(dp[i][w], dp[i - 1][w - wi] + vi)
    return dp[n][capacity]
