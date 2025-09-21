def knapsack_01(weights, values, capacity):
    n = len(weights)

    # Create DP table
    dp = [[0] * (capacity + 1) for _ in range(n + 1)]

    # Fill DP table
    for i in range(1, n + 1):
        for w in range(capacity + 1):
            # Case 1: Don't include current item
            dp[i][w] = dp[i-1][w]

            # Case 2: Include current item (if it fits)
            # BUG FIX: use i-1 because weights[] and values[] are 0-based,
            # while our DP table is 1-based for items.
            if weights[i-1] <= w:
                include_value = dp[i-1][w - weights[i-1]] + values[i-1]
                dp[i][w] = max(dp[i][w], include_value)

    return dp[n][capacity]


# Test case:
weights = [1, 3, 4, 5]
values = [1, 4, 5, 7]
capacity = 7

result = knapsack_01(weights, values, capacity)
print(f"Maximum value: {result}")
# Expected: 9 (items with weights 3+4, values 4+5)


# Edge case:
weights2 = [2, 3, 4, 5]
values2 = [3, 4, 5, 6]
capacity2 = 5

result2 = knapsack_01(weights2, values2, capacity2)
print(f"Edge case result: {result2}")
# Expected: 7 (items with weights 2+3, values 3+4)
