def subset_sum(arr, target):
    n = len(arr)
    dp = [[False]*(target+1) for _ in range(n+1)]
    for i in range(n+1):
        dp[i][0] = True
    for i in range(1, n+1):
        for s in range(1, target+1):
            if arr[i-1] <= s:
                dp[i][s] = dp[i-1][s] or dp[i-1][s-arr[i-1]]
            else:
                dp[i][s] = dp[i-1][s]
    return "Yes" if dp[n][target] else "No"

print(subset_sum([3,34,4,12,5,2], 9))
print(subset_sum([1,2,3], 7))
