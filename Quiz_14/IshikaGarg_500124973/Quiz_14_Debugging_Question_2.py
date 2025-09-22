1. The indexing bug in array access

In this line:

if weights[i] <= w:
    include_value = dp[i-1][w - weights[i]] + values[i]


The bug is that weights[i] and values[i] are used directly.

But i in the DP loop goes from 1 to n, while Python lists are 0-based.

So on the last iteration (i = n), the code tries to access weights[n] and values[n] — which is out of range.

2. What happens when the function tries out-of-bounds indices

In Python, weights[n] or values[n] will raise an IndexError if the test data pushes execution there.

If somehow not triggered immediately (e.g., depending on loop conditions), the algorithm is still comparing and adding the wrong items, so results become incorrect.

3. Correct indexing for weights and values arrays

It should use i-1 when accessing weights and values:

if weights[i-1] <= w:
    include_value = dp[i-1][w - weights[i-1]] + values[i-1]
    dp[i][w] = max(dp[i][w], include_value)

Fixed function
def knapsack_01(weights, values, capacity):
    n = len(weights)

    dp = [[0] * (capacity + 1) for _ in range(n + 1)]

    for i in range(1, n + 1):
        for w in range(capacity + 1):
            # Don't include current item
            dp[i][w] = dp[i-1][w]

            # Include current item if possible
            if weights[i-1] <= w:  # FIXED indexing
                include_value = dp[i-1][w - weights[i-1]] + values[i-1]
                dp[i][w] = max(dp[i][w], include_value)

    return dp[n][capacity]

Test results after fixing
weights = [1, 3, 4, 5]
values = [1, 4, 5, 7]  
capacity = 7
print(knapsack_01(weights, values, capacity))  
# 9 (3 + 4 weights, 4 + 5 values)

weights2 = [2, 3, 4, 5]
values2 = [3, 4, 5, 6]
capacity2 = 5
print(knapsack_01(weights2, values2, capacity2))  
# ✅ 7 (items with weights 2 + 3, values 3 + 4)
