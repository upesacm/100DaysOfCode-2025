def min_coins(coins, amount):
    if amount < 0:
        return -1
    coins = sorted(coins, reverse=True)
    count = 0
    for coin in coins:
        while amount >= coin:
            amount -= coin
            count += 1
    return count if amount == 0 else -1

# Example 1
coins = [1, 2, 5, 10]
amount = 23
print(min_coins(coins, amount))  # Output: 4 (greedy: 10+10+2+1)

# Example 2
coins = [1, 5, 6, 9]
amount = 11
print(min_coins(coins, amount))  # Output: 3 (greedy: 9+1+1; note: optimal is 2 using 5+6)
