Your task: Use a monotonic stack to efficiently compute stock price spans by tracking 
previous higher prices for optimal time-series analysis.

def calculate_stock_spans(prices):
    spans = []
    stack = []

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
