coins = list(map(int, input("Enter coin denominations separated by space: ").split()))
amount = int(input("Enter the amount: "))

coins.sort(reverse=True)
count = 0
i = 0

while amount > 0 and i < len(coins):
    if coins[i] <= amount:
        num = amount // coins[i]
        count += num
        amount -= coins[i] * num
    i += 1

if amount == 0:
    print(count)
else:
    print("Exact amount cannot be formed with given coins")
