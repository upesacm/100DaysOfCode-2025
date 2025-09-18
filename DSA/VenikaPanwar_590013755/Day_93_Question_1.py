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
        # Either rob current house + best from i-2, or skip current house
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
    
    prev2 = nums[0]  # dp[i-2]
    prev1 = max(nums[0], nums[1])  # dp[i-1]
    
    for i in range(2, len(nums)):
        current = max(prev1, prev2 + nums[i])
        prev2, prev1 = prev1, current
    
    return prev1

if __name__ == "__main__":
    # Test cases
    houses1 = [1, 2, 3, 1]
    print(f"Max rob amount for {houses1}: {rob(houses1)}")  # Output: 4
    
    houses2 = [2, 7, 9, 3, 1]
    print(f"Max rob amount for {houses2}: {rob(houses2)}")  # Output: 12
    
    # Test optimized version
    print(f"Max rob amount (optimized) for {houses1}: {rob_optimized(houses1)}")  # Output: 4
    print(f"Max rob amount (optimized) for {houses2}: {rob_optimized(houses2)}")  # Output: 12