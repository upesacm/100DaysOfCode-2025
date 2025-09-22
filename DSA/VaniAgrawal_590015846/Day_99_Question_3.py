# Coin Change 2 (Number of Ways)
def change(amount, coins):
    dp = [0]*(amount+1)
    dp[0] = 1
    for coin in coins:
        for x in range(coin, amount+1):
            dp[x] += dp[x-coin]
    return dp[amount]

amount = int(input())
coins = list(map(int, input().split()))
print(change(amount, coins))
