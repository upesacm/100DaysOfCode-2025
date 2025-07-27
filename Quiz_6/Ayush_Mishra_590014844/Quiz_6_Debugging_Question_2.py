def calculate_stock_span(prices):
    stack = []
    spans = []

    for i in range(len(prices)):
        while stack and prices[stack[-1]] <= prices[i]:
            stack.pop()

        if not stack:
            span = i + 1
        else:
            span = i - stack[-1]

        spans.append(span)
        stack.append(i)

    return spans

prices = [100, 80, 60, 70, 60, 75, 85]
result = calculate_stock_span(prices)
print(f"Stock spans: {result}")
