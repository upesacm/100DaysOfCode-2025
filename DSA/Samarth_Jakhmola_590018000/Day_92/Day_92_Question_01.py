def fibonacci(n):
    if n == 0:
        return 0
    elif n == 1:
        return 1
    
    dp = [0] * (n + 1)   # DP array
    dp[0], dp[1] = 0, 1

    for i in range(2, n + 1):
        dp[i] = dp[i - 1] + dp[i - 2]

    return dp[n]

try:
    n = int(input("Ente the value of N : "))
    print(f"The Nth fibonacci number is : {fibonacci(n)}")
except:
    print("Invalid input. Please try with a valid input.")
