# 1. Identify the indexing bug in array access 
# -- You're accessing weights[i] and values[i], but weights and values are 0-indexed, while i starts from 1. So weights[i] refers to the (i+1)th item, which is incorrect and will eventually go out of bounds when i == n.

# 2. Explain what happens when the function tries to access out-of-bounds indices
# -- When i == n (i.e., the last iteration), weights[i] and values[i] attempt to access weights[n] and values[n], which do not exist. This causes:
# IndexError in strict environments.
# Or worse: silent logic errors, where the wrong item is used or skipped, leading to incorrect results.

# 3. What should be the correct indexing for weights and values arrays?
def knapsack_01(weights, values, capacity):
    n = len(weights)
    dp = [[0] * (capacity + 1) for _ in range(n + 1)]

    for i in range(1, n + 1):
        for w in range(capacity + 1):
            dp[i][w] = dp[i - 1][w]
            if weights[i - 1] <= w:
                include_value = dp[i - 1][w - weights[i - 1]] + values[i - 1]
                dp[i][w] = max(dp[i][w], include_value)

    return dp[n][capacity]
