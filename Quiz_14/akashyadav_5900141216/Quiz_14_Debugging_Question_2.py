def knapsack_01(weights, values, capacity):
    n = len(weights)
    dp = [[0] * (capacity + 1) for _ in range(n + 1)]
    for i in range(1, n + 1):
        for w in range(capacity + 1):
            dp[i][w] = dp[i-1][w]
            if weights[i] <= w:
                include_value = dp[i-1][w - weights[i]] + values[i]
                dp[i][w] = max(dp[i][w], include_value)
    return dp[n][capacity]

#1.The indexing bug in array access:
#The code uses weights[i] and values[i], but both arrays are 0-indexed while the loop variable i starts from 1, 
#so it should use weights[i-1] and values[i-1] everywhere instead.
#
#2.If i == n, then weights[i] or values[i] will try to access one-past-end elements causing an IndexError,
#or during valid i, accesses the wrong item (off-by-one) leading to incorrect computation and wrong results.
