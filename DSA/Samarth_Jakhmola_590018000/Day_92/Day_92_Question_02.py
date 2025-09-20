def climb_stairs(n):
    dp = [0] * (n + 1)
    dp[0], dp[1] = 1, 1  # base cases

    for i in range(2, n + 1):
        dp[i] = dp[i - 1] + dp[i - 2]

    return dp[n]

try:
    n = int(input("Enter the value of N (number of steps) : "))
    print(f"The total number of ways to reach to the top are : {climb_stairs(n)}")
except:
    print("Invalid input. Please try with a valid input.")
