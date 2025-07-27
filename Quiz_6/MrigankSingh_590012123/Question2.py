def calculate_stock_span(prices):
    stack = []
    spans = []

    for i in range(len(prices)):
        # Bug was using >= when we should use <=
        # Current condition removes prices greater than current price
        # when we want to remove prices less than or equal to current
        while stack and prices[stack[-1]] <= prices[i]:  # Fixed condition
            stack.pop()

        if not stack:
            span = i + 1
        else:
            span = i - stack[-1]

        spans.append(span)
        stack.append(i)

    return spans


# Test case:
prices = [100, 80, 60, 70, 60, 75, 85]
result = calculate_stock_span(prices)
print(f"Stock spans: {result}")
# Expected: [1, 1, 1, 2, 1, 4, 6]
# Now correctly returns: [1, 1, 1, 2, 1, 4, 6]
