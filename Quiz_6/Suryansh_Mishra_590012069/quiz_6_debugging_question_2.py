def calculate_stock_span(prices):
    stack = []
    spans = []

    for i in range(len(prices)):
        # Fix: Pop smaller or equal elements
        while stack and prices[stack[-1]] <= prices[i]:
            stack.pop()

        if not stack:
            span = i + 1
        else:
            span = i - stack[-1]

        spans.append(span)
        stack.append(i)

    return spans
