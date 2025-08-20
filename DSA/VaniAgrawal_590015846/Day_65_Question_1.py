# Implement greedy coin selection using largest denomination strategy to minimize coin count while achieving exact amount targets with optimal efficiency.

coins = list(map(int, input("Enter coin denominations separated by space: ").split()))
amount = int(input("Enter the amount: "))
coins.sort(reverse=True)
count = 0
used = []

for coin in coins:
    while amount >= coin:
        amount -= coin
        count += 1
        used.append(coin)

print(count, "(", "+".join(map(str, used)), ")")
