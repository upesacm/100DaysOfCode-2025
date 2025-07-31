def stock_span(prices):
    stack = []
    span = []
    for i, price in enumerate(prices):
        while stack and prices[stack[-1]] <= price:
            stack.pop()
        if not stack:
            span.append(i + 1)
        else:
            span.append(i - stack[-1])
        stack.append(i)
    return span

print(stock_span([100, 80, 60, 70, 60, 75, 85]))
print(stock_span([10, 20, 30]))
