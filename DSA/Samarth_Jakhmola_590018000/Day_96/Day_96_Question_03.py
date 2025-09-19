def partition_equal_subset_sum(array, n):
    total_sum = sum(array)

    # If total sum is odd, can't partition equally
    if total_sum % 2 != 0:
        return False
    
    target = total_sum // 2

    # Initialize DP table
    dp = [[False for _ in range(target + 1)] for _ in range(n + 1)]

    # Base case : sum 0 always possible
    for i in range(1, n + 1):
        dp[i][0] = True

    # Fill DP table
    for i in range(1, n + 1):
        for s in range(1, target + 1):
            if array[i - 1] <= s:
                dp[i][s] = dp[i - 1][s] or dp[i - 1][s - array[i - 1]]
            else:
                dp[i][s] = dp[i -1][s]

    return dp[n][target]

n = int(input("Enter the number of elements : "))
array = list(map(int, input("Enter the elements separated by spaces : ").split()))

print("Yes" if partition_equal_subset_sum(array, n) else "No")
