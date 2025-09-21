def can_partition(nums):
    total = sum(nums)
    if total % 2 != 0:
        return "No"
    target = total // 2
    n = len(nums)
    dp = [[False]*(target+1) for _ in range(n+1)]
    for i in range(n+1):
        dp[i][0] = True
    for i in range(1, n+1):
        for s in range(1, target+1):
            if nums[i-1] <= s:
                dp[i][s] = dp[i-1][s] or dp[i-1][s-nums[i-1]]
            else:
                dp[i][s] = dp[i-1][s]
    return "Yes" if dp[n][target] else "No"

print(can_partition([1,5,11,5]))
print(can_partition([1,2,3,5]))
