def coin_change(coins, amount):
    dp = [float('inf')] * (amount + 1)
    dp[0] = 0
    for i in range(1, amount + 1):
        for coin in coins:
            if i - coin >= 0:
                dp[i] = min(dp[i], dp[i - coin] + 1)
    return dp[amount] if dp[amount] != float('inf') else -1

coins = list(map(int, input("Enter coin denominations separated by space: ").split()))
amount = int(input("Enter target amount: "))
print(coin_change(coins, amount))
