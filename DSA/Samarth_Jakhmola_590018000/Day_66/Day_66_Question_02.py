def max_profit(prices):
    min_price = float('inf')
    best = 0
    for p in prices:
        if p < min_price:
            min_price = p
        best = max(best, p - min_price)
    return best

try:
    prices = list(map(int, input("Enter the prices of the stocks, separated by spaces : ").split()))
    print(max_profit(prices))
except:
    print("Invalid input. Please try with a valid input.")
