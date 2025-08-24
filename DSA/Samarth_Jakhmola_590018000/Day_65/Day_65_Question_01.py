def minimmum_coins(coins, amount):
    coins.sort(reverse = True)

    min_count = float('inf')
    result = []

    for i in range(len(coins) + 1):
        temp_target = amount
        count = 0
        combo = []

        for coin in coins[i:]:   # Excludes ith largest coin
            while temp_target >= coin:
                temp_target -= coin
                count += 1
                combo.append(coin)

        if temp_target == 0 and count < min_count:
            min_count = count
            result = combo[:]

    if result == float('inf'):
        return "Not possible"
    else:
        return f"{min_count} ({'+'.join(map(str, result))})"
    
try:
    coins = list(map(int, input("Enter the different denominations of coins separated by spaces : ").split()))
    amount = int(input("Enter the end times of the activities separated by spaces : "))
    print(minimmum_coins(coins, amount))
except:
    print("Invalid input. Please try with a valid input.")
