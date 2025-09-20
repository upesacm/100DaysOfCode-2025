def knapsack(weights, values, W, n):
    # Initialize DP table with (n + 1) x (W + 1)
    dp = [[0 for _ in range(W + 1)] for _ in range(n + 1)]

    # Fill DP table
    for i in range(1, n + 1):
        for w in range(1, W + 1):
            if weights[i - 1] <= w:
                # Include or exclude item
                dp[i][w] = max(dp[i - 1][w], values[i - 1] + dp[i - 1][w - weights[i - 1]])
            else:
                # Can't include item 
                dp[i][w] = dp[i - 1][w]

    return dp[n][W]

n = int(input("Enter the number of items : "))

weights = list(map(int, input("Enter the weights separated by spaces : ").split()))
values = list(map(int, input("Enter the values separated by spaces : ").split()))
W = int(input("Enter the knapsack capacity : "))

print(knapsack(weights, values, W, n))
