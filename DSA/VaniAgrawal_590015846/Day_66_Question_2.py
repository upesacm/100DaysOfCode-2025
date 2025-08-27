#  Implement greedy stock trading using minimum price tracking to identify optimal buy-sell timing for maximum single-transaction profit.
n = int(input())
prices = list(map(int, input().split()))
min_price = float('inf')
max_profit = 0
for p in prices:
    min_price = min(min_price, p)
    max_profit = max(max_profit, p - min_price)
print(max_profit)
