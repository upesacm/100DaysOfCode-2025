#1.Bug in the stack condition:while stack and prices[stack[-1]] >= prices[i]
#2.The current logic discards all days with higher or equal prices, which results in shorter spans.
#It underestimates the span when earlier prices were less than or equal, which should have been counted.
#3. Correct condition should be:
#while stack and prices[stack[-1]] <= prices[i]
#correct code
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
