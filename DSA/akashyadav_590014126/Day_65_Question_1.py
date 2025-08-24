def min_coins(coins, amount):
    coins.sort(reverse=True) 
    count = 0
    for coin in coins:
        if amount >= coin:
            num = amount // coin
            count += num
            amount -= coin * num
    return count if amount == 0 else -1  

# Example
print(min_coins([1, 5, 6, 9], 11))   