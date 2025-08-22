def max_profit(prices):
    if not prices:
        return 0
    min_price=float('inf')
    max_profit=0

    for price in prices:
        if price < min_price:
            min_price=price
        else:
            profit=price-min_price
            max_profit=max(max_profit,profit)

    return max_profit