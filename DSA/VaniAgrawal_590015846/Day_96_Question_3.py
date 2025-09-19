# Partition Equal Subset Sum
def can_partition(nums):
    total = sum(nums)
    if total % 2 != 0:
        return False
    target = total // 2
    dp = [False]*(target+1)
    dp[0] = True
    for num in nums:
        for s in range(target, num-1, -1):
            dp[s] = dp[s] or dp[s-num]
    return dp[target]

nums = list(map(int, input().split()))
print("Yes" if can_partition(nums) else "No")
