def knapsack_01(weights, values, capacity):
    n = len(weights)

    # Create DP table
    dp = [[0] * (capacity + 1) for _ in range(n + 1)]

    # Fill DP table
    for i in range(1, n + 1):
        for w in range(capacity + 1):
            # Case 1: Don't include current item
            dp[i][w] = dp[i - 1][w]

            # BUG: originally used weights[i] and values[i]
            # This is incorrect because weights/values are 0-indexed,
            # while 'i' in this loop starts from 1 due to DP padding.
            # So correct access should be weights[i-1] and values[i-1].
            if weights[i - 1] <= w:  
                include_value = dp[i - 1][w - weights[i - 1]] + values[i - 1]
                dp[i][w] = max(dp[i][w], include_value)

    return dp[n][capacity]


# Test case:
weights = [1, 3, 4, 5]
values = [1, 4, 5, 7]  
capacity = 7

result = knapsack_01(weights, values, capacity)
print(f"Maximum value: {result}")
# Expected: 9 (items with weights 3+4, values 4+5)
# Buggy version tries to access weights[i], values[i] when i = n,
# which causes IndexError: list index out of range.

# Edge case:
weights2 = [2, 3, 4, 5]
values2 = [3, 4, 5, 6]
capacity2 = 5

result2 = knapsack_01(weights2, values2, capacity2)
print(f"Edge case result: {result2}")
# Expected: 7 (items with weights 2+3, values 3+4)
# Buggy version again fails at out-of-bounds access.
