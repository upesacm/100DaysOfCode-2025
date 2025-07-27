def calculate_stock_span(prices):
    stack = []  # Holds indices
    spans = []

    for i in range(len(prices)):
        # Pop while current price >= price at top of stack
        while stack and prices[i] >= prices[stack[-1]]:
            stack.pop()

        if not stack:
            span = i + 1
        else:
            span = i - stack[-1]

        spans.append(span)
        stack.append(i)

    return spans


# Test case
prices = [100, 80, 60, 70, 60, 75, 85]
result = calculate_stock_span(prices)
print(f"Stock spans: {result}")
