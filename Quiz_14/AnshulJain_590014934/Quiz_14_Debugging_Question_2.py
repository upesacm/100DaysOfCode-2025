def knapsack_01(weights, values, capacity):
    n = len(weights)

    # Create DP table
    dp = [[0] * (capacity + 1) for _ in range(n + 1)]

    # Fill DP table
    for i in range(1, n + 1):
        for w in range(capacity + 1):
            # Don't include current item
            dp[i][w] = dp[i-1][w]

            # Include current item if possible
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

#task Answers:-
# 1)The indexing bug is that the code uses weights[i] and values[i] instead of weights[i-1] and values[i-1] inside the loop where i ranges from 1 to n.
#  The arrays weights and values are zero-based but the DP table uses 1-based indexing for items.

# 2)When the function tries to access weights[i] or values[i] for i == n (i.e., last iteration), it accesses an out-of-bounds index,
# which causes an "index out of range" error or undefined behavior depending on environment. For other values of i, it accesses a shifted element not corresponding to the current item.

# 3)The correct indexing should be weights[i-1] and values[i-1] to align the 1-based DP table indexing with the 0-based Python arrays for items.
# This ensures accessing the correct item weight and value at each iteration.