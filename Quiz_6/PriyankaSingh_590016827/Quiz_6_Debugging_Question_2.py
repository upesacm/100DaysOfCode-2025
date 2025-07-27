def calculate_stock_span(prices):
    stack = []
    spans = []

    for i in range(len(prices)):
        # Fix: maintain decreasing stack
        while stack and prices[stack[-1]] <= prices[i]:
            stack.pop()

        span = i + 1 if not stack else i - stack[-1]
        spans.append(span)
        stack.append(i)

    return spans


# Test case
prices = [100, 80, 60, 70, 60, 75, 85]
result = calculate_stock_span(prices)
print(f"Stock spans: {result}")  # Output: [1, 1, 1, 2, 1, 4, 6]

