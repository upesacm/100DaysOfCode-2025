def coin_change(coins, amount):
    """
    Finds minimum number of coins needed to make the target amount.
    Time: O(amount * len(coins)), Space: O(amount)
    """
    if amount == 0:
        return 0
    dp = [float('inf')] * (amount + 1)
    dp[0] = 0
    for i in range(1, amount + 1):
        for coin in coins:
            if coin <= i:
                dp[i] = min(dp[i], dp[i - coin] + 1)
    return dp[amount] if dp[amount] != float('inf') else -1

if __name__ == "__main__":
    print(coin_change([1, 2, 5], 11))  # Output: 3
    print(coin_change([2], 3))         # Output: -1