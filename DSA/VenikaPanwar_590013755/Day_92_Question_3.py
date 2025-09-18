def min_cost_climbing_stairs(cost):
    """
    Finds minimum cost to reach the top of stairs.
    Can start from step 0 or 1, climb 1 or 2 steps at a time.
    Time: O(n), Space: O(n)
    """
    n = len(cost)
    if n == 0:
        return 0
    if n == 1:
        return cost[0]
    
    # dp[i] represents minimum cost to reach step i
    dp = [0] * n
    dp[0] = cost[0]  # Cost to reach step 0
    dp[1] = cost[1]  # Cost to reach step 1
    
    # For each step, min cost = step cost + min(cost from i-1, cost from i-2)
    for i in range(2, n):
        dp[i] = cost[i] + min(dp[i - 1], dp[i - 2])
    
    # Can reach top from either last or second-to-last step
    return min(dp[n - 1], dp[n - 2])

def min_cost_climbing_stairs_optimized(cost):
    """
    Space-optimized version using only two variables.
    Time: O(n), Space: O(1)
    """
    n = len(cost)
    if n == 0:
        return 0
    if n == 1:
        return cost[0]
    
    prev2, prev1 = cost[0], cost[1]
    
    for i in range(2, n):
        curr = cost[i] + min(prev1, prev2)
        prev2, prev1 = prev1, curr
    
    return min(prev1, prev2)

if __name__ == "__main__":
    # Test cases
    cost1 = [10, 15, 20]
    print(f"Min cost for {cost1}: {min_cost_climbing_stairs(cost1)}")  # Output: 15
    
    cost2 = [1, 100, 1, 1, 1, 100, 1, 1, 100, 1]
    print(f"Min cost for {cost2}: {min_cost_climbing_stairs(cost2)}")  # Output: 6
    
    # Test space-optimized version
    print(f"Min cost for {cost1} (optimized): {min_cost_climbing_stairs_optimized(cost1)}")  # Output: 15
    print(f"Min cost for {cost2} (optimized): {min_cost_climbing_stairs_optimized(cost2)}")  # Output: 6
    
    # Explain the optimal path for cost2
    print("\nOptimal path for [1,100,1,1,1,100,1,1,100,1]:")
    print("Start → 0(cost:1) → 2(cost:1) → 3(cost:1) → 4(cost:1) → 6(cost:1) → 7(cost:1) → Top")
    print("Total cost: 1+1+1+1+1+1 = 6")