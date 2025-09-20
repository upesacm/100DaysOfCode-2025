def climb_stairs(n):
    """
    Counts number of ways to climb n stairs (1 or 2 steps at a time).
    This is essentially Fibonacci sequence starting from 1, 1.
    Time: O(n), Space: O(n)
    """
    if n <= 1:
        return 1
    
    # dp[i] represents number of ways to reach step i
    dp = [0] * (n + 1)
    dp[0] = 1  # One way to stay at ground (do nothing)
    dp[1] = 1  # One way to reach step 1
    
    # For each step, ways = ways to reach (i-1) + ways to reach (i-2)
    for i in range(2, n + 1):
        dp[i] = dp[i - 1] + dp[i - 2]
    
    return dp[n]

def climb_stairs_optimized(n):
    """
    Space-optimized version using only two variables.
    Time: O(n), Space: O(1)
    """
    if n <= 1:
        return 1
    
    prev2, prev1 = 1, 1  # ways[0] = 1, ways[1] = 1
    for i in range(2, n + 1):
        curr = prev1 + prev2
        prev2, prev1 = prev1, curr
    
    return prev1

if __name__ == "__main__":
    # Test cases
    print(f"Ways to climb 3 steps: {climb_stairs(3)}")  # Output: 3
    print(f"Ways to climb 4 steps: {climb_stairs(4)}")  # Output: 5
    
    # Test space-optimized version
    print(f"Ways to climb 3 steps (optimized): {climb_stairs_optimized(3)}")  # Output: 3
    print(f"Ways to climb 4 steps (optimized): {climb_stairs_optimized(4)}")  # Output: 5
    
    # Show the paths for n=3
    print("\nPaths for n=3:")
    print("Path 1: 1+1+1")
    print("Path 2: 1+2")
    print("Path 3: 2+1")