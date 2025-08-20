def min_coins(coins, amount):
    coins.sort(reverse=True)
    count = 0
    for coin in coins:
        if amount >= coin:
            num = amount // coin
            count += num
            amount -= num * coin
    return count
