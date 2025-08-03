def calculate_stock_span(prices):
    stack = []  # This will store indices of the days
    spans = []  # This will store the final span for each day

    for i in range(len(prices)):
        # Pop elements from the stack while the current price is higher or equal
        # This helps us find the nearest previous day with a higher price
        while stack and prices[stack[-1]] <= prices[i]:
            stack.pop()

        # If the stack is empty, it means no previous higher price exists
        if not stack:
            span = i + 1
        else:
            # Span is the difference between current index and index of last higher price
            span = i - stack[-1]

        spans.append(span)
        stack.append(i)  # Push current index onto the stack

    return spans


# Test case
prices = [100, 80, 60, 70, 60, 75, 85]
result = calculate_stock_span(prices)
print(f"Stock spans: {result}")
