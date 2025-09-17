# Longest Increasing Subsequence (LIS)
def length_of_lis(nums):
    from bisect import bisect_left
    dp = []
    for num in nums:
        idx = bisect_left(dp, num)
        if idx == len(dp):
            dp.append(num)
        else:
            dp[idx] = num
    return len(dp)

nums = eval(input())
print(length_of_lis(nums))
