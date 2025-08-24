n = int(input("Enter number of days: "))# taking input from the user 
prices = list(map(int, input("Enter stock prices: ").split()))#taking input from the user
min_price = prices[0]
max_profit = 0
for price in prices:
    min_price = min(min_price, price)
    max_profit = max(max_profit, price - min_price)
print(max_profit)
#for exapmple:
# Input:
# Enter number of days: 5
# Enter stock prices: 7 1 5 3 6 4
# Output:5