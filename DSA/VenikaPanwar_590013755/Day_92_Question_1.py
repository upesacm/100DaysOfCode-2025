def fibonacci_dp(n):
    """
    Computes nth Fibonacci number using dynamic programming.
    Time: O(n), Space: O(n)
    """
    if n <= 1:
        return n
    
    # Create DP array to store computed values
    dp = [0] * (n + 1)
    dp[0] = 0
    dp[1] = 1
    
    # Fill DP array bottom-up
    for i in range(2, n + 1):
        dp[i] = dp[i - 1] + dp[i - 2]
    
    return dp[n]

def fibonacci_optimized(n):
    """
    Space-optimized version using only two variables.
    Time: O(n), Space: O(1)
    """
    if n <= 1:
        return n
    
    prev2, prev1 = 0, 1
    for i in range(2, n + 1):
        curr = prev1 + prev2
        prev2, prev1 = prev1, curr
    
    return prev1

if __name__ == "__main__":
    # Test cases
    print(f"F(5) = {fibonacci_dp(5)}")  # Output: 5
    print(f"F(7) = {fibonacci_dp(7)}")  # Output: 13
    
    # Test space-optimized version
    print(f"F(5) optimized = {fibonacci_optimized(5)}")  # Output: 5
    print(f"F(7) optimized = {fibonacci_optimized(7)}")  # Output: 13