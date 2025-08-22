def greedy_coin_change(coins, amount):
    coins.sort(reverse=True)  # sort descending for greedy
    result = []
    count = 0

    for coin in coins:
        while amount >= coin:
            amount -= coin
            result.append(coin)
            count += 1

    print("Coins used:", result)
    return count

print("Minimum coins:", greedy_coin_change([1, 2, 5, 10], 23)) 
print("Minimum coins:", greedy_coin_change([1, 5, 6, 9], 11))  
