def minimum_cost_climbing_stairs(cost):
    n = len(cost)
    dp = [0] * n
    dp[0], dp[1] = cost[0], cost[1]

    for i in range(2, n):
        dp[i] = cost[i] + min(dp[i - 1], dp[i - 2])

    # minimum cost to reach the top (beyond last step)
    return min(dp[n - 1], dp[n - 2])

try:
    cost = list(map(int, input("Enter the step costs, separated by spaces : ").split()))
    print(f"The minimum cost to reach to the top is : {minimum_cost_climbing_stairs(cost)}")
except:
    print("Invalid input. Please try with a valid input.")
