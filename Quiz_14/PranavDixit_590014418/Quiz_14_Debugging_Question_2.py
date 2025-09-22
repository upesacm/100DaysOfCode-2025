def knapsack_01(weights, values, capacity):
    n = len(weights)
    dp = [[0] * (capacity + 1) for _ in range(n + 1)]

    for i in range(1, n + 1):
        for w in range(capacity + 1):
            dp[i][w] = dp[i - 1][w]
            if weights[i - 1] <= w:
                include_value = dp[i - 1][w - weights[i - 1]] + values[i - 1]
                dp[i][w] = max(dp[i][w], include_value)
    return dp[n][capacity]


weights = [1, 3, 4, 5]
values = [1, 4, 5, 7]
capacity = 7
print("Maximum value:", knapsack_01(weights, values, capacity))

weights2 = [2, 3, 4, 5]
values2 = [3, 4, 5, 6]
capacity2 = 5
print("Edge case result:", knapsack_01(weights2, values2, capacity2))

"""
Answers:
1. The bug was using weights[i] and values[i]. Correct is weights[i-1], values[i-1].
2. This caused out-of-bounds errors when i == n.
3. Correct indexing is with i-1.
"""
