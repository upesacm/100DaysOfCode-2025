def knapsack_01(weights, values, capacity):
    n = len(weights)
    dp = [[0] * (capacity + 1) for _ in range(n + 1)]

    for i in range(1, n + 1):
        for w in range(capacity + 1):
            # Don't include current item
            dp[i][w] = dp[i-1][w]

            # Include current item if possible
            if weights[i-1] <= w:  # ✅ corrected index
                include_value = dp[i-1][w - weights[i-1]] + values[i-1]
                dp[i][w] = max(dp[i][w], include_value)

    return dp[n][capacity]


# 1️ Indexing Bug

#Inside the loop:
# if weights[i] <= w:  
    # include_value = dp[i-1][w - weights[i]] + values[i]
# Bug: i runs from 1 → n, but Python lists weights and values are 0-indexed.
# When i == n (last iteration), weights[i] and values[i] try to access index n, which does not exist.

# 2️ Effect of Out-of-Bounds Access

# Runtime Error: For the given test case, weights = [1,3,4,5], when i=4 (n=4), the code tries to access weights[4] and values[4], which raises:
# IndexError: list index out of range
# If this error is suppressed (in some contexts), the algorithm would still read wrong values, producing incorrect results (often 0 or a partial value).

# 3️ Correct Indexing

# The DP table uses an extra row (i=0) for the base case (no items).
# Correct item index: i-1
# Fix:
# if weights[i-1] <= w:
    # include_value = dp[i-1][w - weights[i-1]] + values[i-1]
