def lengthOfLIS_n2(nums):
    n = len(nums)
    dp = [1] * n
    for i in range(n):
        for j in range(i):
            if nums[i] > nums[j]:
                dp[i] = max(dp[i], dp[j] + 1)
    return max(dp)

print(lengthOfLIS_n2([10, 9, 2, 5, 3, 7, 101, 18]))  # Output: 4
print(lengthOfLIS_n2([0, 1, 0, 3, 2, 3]))            # Output: 4
