def rob(nums):
    """
    Finds maximum amount that can be robbed without robbing adjacent houses.
    Time: O(n), Space: O(n)
    """
    if not nums:
        return 0
    if len(nums) == 1:
        return nums[0]
    n = len(nums)
    dp = [0] * n
    dp[0] = nums[0]
    dp[1] = max(nums[0], nums[1])
    for i in range(2, n):
        dp[i] = max(dp[i-1], dp[i-2] + nums[i])
    return dp[n-1]

def rob_optimized(nums):
    """
    Space-optimized version using only two variables.
    Time: O(n), Space: O(1)
    """
    if not nums:
        return 0
    if len(nums) == 1:
        return nums[0]
    prev2 = nums[0]
    prev1 = max(nums[0], nums[1])
    for i in range(2, len(nums)):
        curr = max(prev1, prev2 + nums[i])
        prev2, prev1 = prev1, curr
    return prev1

if __name__ == "__main__":
    print(rob([1, 2, 3, 1]))  # Output: 4
    print(rob([2, 7, 9, 3, 1]))  # Output: 12
    print(rob_optimized([1, 2, 3, 1]))  # Output: 4
    print(rob_optimized([2, 7, 9, 3, 1]))  # Output: 12