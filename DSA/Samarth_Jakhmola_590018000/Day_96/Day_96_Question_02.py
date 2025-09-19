def subset_sum(array, target, n):
    # Initialize DP table
    dp = [[False for _ in range(target + 1)] for _ in range(n + 1)]

    # Base case : sum 0 is always possible
    for i in range(n + 1):
        dp[i][0] = True

    # Fill DP table
    for i in range(1, n + 1):
        for s in range(1, target + 1):
            if array[i - 1] <= s:
                dp[i][s] = dp[i - 1][s] or dp[i - 1][s - array[i-1]]
            else:
                dp[i][s] = dp[i - 1][s]

    return dp[n][target]

n = int(input("Enter the number of elements : "))

array = list(map(int, input("Enter the elements separated by spaces : ").split()))
target = int(input("Enter the target sum : "))

print("Yes" if subset_sum(array, target, n) else "No")
