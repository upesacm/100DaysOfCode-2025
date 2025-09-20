def coin_change(coins, amount):
    """
    Finds minimum number of coins needed to make the target amount.
    Time: O(amount * len(coins)), Space: O(amount)
    """
    if amount == 0:
        return 0
    
    # Initialize DP array with infinity (impossible values)
    dp = [float('inf')] * (amount + 1)
    dp[0] = 0  # Base case: 0 coins needed for amount 0
    
    # For each amount from 1 to target
    for i in range(1, amount + 1):
        # Try each coin denomination
        for coin in coins:
            if coin <= i:  # Can use this coin
                dp[i] = min(dp[i], dp[i - coin] + 1)
    
    return dp[amount] if dp[amount] != float('inf') else -1

def coin_change_with_solution(coins, amount):
    """
    Returns minimum coins needed and the actual coin combination.
    """
    if amount == 0:
        return 0, []
    
    dp = [float('inf')] * (amount + 1)
    parent = [-1] * (amount + 1)  # To track which coin was used
    dp[0] = 0
    
    for i in range(1, amount + 1):
        for coin in coins:
            if coin <= i and dp[i - coin] + 1 < dp[i]:
                dp[i] = dp[i - coin] + 1
                parent[i] = coin
    
    if dp[amount] == float('inf'):
        return -1, []
    
    # Reconstruct solution
    result = []
    current = amount
    while current > 0:
        coin_used = parent[current]
        result.append(coin_used)
        current -= coin_used
    
    return dp[amount], result

if __name__ == "__main__":
    # Test cases
    coins1 = [1, 2, 5]
    amount1 = 11
    print(f"Min coins for amount {amount1} with coins {coins1}: {coin_change(coins1, amount1)}")  # Output: 3
    
    coins2 = [2]
    amount2 = 3
    print(f"Min coins for amount {amount2} with coins {coins2}: {coin_change(coins2, amount2)}")  # Output: -1
    
    # Test with solution tracking
    min_coins, solution = coin_change_with_solution(coins1, amount1)
    print(f"Min coins: {min_coins}, Solution: {solution}")  # Output: Min coins: 3, Solution: [1, 5, 5]
    
    # Show DP table construction for first example
    print(f"\nDP table for coins {coins1}, amount {amount1}:")
    dp = [float('inf')] * (amount1 + 1)
    dp[0] = 0
    
    for i in range(1, amount1 + 1):
        for coin in coins1:
            if coin <= i:
                dp[i] = min(dp[i], dp[i - coin] + 1)
        print(f"Amount {i}: {dp[i] if dp[i] != float('inf') else 'impossible'}")