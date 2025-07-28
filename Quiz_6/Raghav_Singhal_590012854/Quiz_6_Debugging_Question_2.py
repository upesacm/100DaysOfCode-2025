# 2. Stock Span Problem Bug

# The following function is intended to calculate the stock span for each day (number of consecutive previous days with smaller or equal prices). It prints the span for each day. However, the function has bugs that cause incorrect outputs for some inputs:


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


# Test case:
prices = [100, 80, 60, 70, 60, 75, 85]
result = calculate_stock_span(prices)
print(f"Stock spans: {result}")



# Expected: [1, 1, 1, 2, 1, 4, 6]
# What does it actually return?
# Switched Greater than and less than
