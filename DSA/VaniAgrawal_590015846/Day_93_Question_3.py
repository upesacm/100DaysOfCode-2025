# Coin Change (Min Coins)
def coin_change(coins, amount):
    dp = [float('inf')] * (amount+1)
    dp[0] = 0
    for coin in coins:
        for x in range(coin, amount+1):
            dp[x] = min(dp[x], dp[x-coin] + 1)
    return -1 if dp[amount] == float('inf') else dp[amount]

coins = list(map(int, input().split()))
amount = int(input())
print(coin_change(coins, amount))
