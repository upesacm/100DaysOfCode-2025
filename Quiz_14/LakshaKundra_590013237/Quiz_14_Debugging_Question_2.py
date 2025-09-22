#answer 1
#the bug is:
#if weights[i] <= w:  
#include_value = dp[valuesghts][w - weights[i]] + values[i]

#answer 2
#When i = n, weights[i] and values[i] try to access an index equal to the array length.
#Python raises IndexError: list index out of range.

#answer 3
#Inside the loops, replace weights[i] and values[i] with:
#eights[i-1], values[i-1]

#corrected code
def knapsack_01(weights, values, capacity):
    n = len(weights)
    dp = [[0] * (capacity + 1) for _ in range(n + 1)]
    for i in range(1, n + 1):
        for w in range(capacity + 1):
            dp[i][w] = dp[i-1][w]
            if weights[i-1] <= w:
                dp[i][w] = max(dp[i][w], dp[i-1][w - weights[i-1]] + values[i-1])
    return dp[n][capacity]

weights = [1, 3, 4, 5]
values = [1, 4, 5, 7]
capacity = 7
print(knapsack_01(weights, values, capacity))

weights2 = [2, 3, 4, 5]
values2 = [3, 4, 5, 6]
capacity2 = 5
print(knapsack_01(weights2, values2, capacity2))
