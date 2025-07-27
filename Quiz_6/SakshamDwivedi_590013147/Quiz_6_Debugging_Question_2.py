def calculate_stock_span(prices):
    stack = []
    spans = []

    for i in range(len(prices)):
        '''It was a simple bug, instead of <= we were using >=, which was removing higher prices instead
            of lower prices.'''
        while stack and prices[stack[-1]] <= prices[i]:
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
# What does it actually return?
# It return [1, 2, 3, 1, 5, 1, 1]
