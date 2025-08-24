def min_coins(coins, amount):
    coins.sort(reverse=True)
    count = 0
    used = []
    for c in coins:
        while amount >= c:
            amount -= c
            count += 1
            used.append(c)
    return count, used

print(min_coins([1, 2, 5, 10], 23))
print(min_coins([1, 5, 6, 9], 11))
