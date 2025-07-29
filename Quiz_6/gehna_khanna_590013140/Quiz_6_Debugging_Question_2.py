#1   while stack and prices[stack[-1]] >= prices[i]:
#2   It removes previous prices that are greater than or equal to the current price but the problem asks for spans of days with prices less than or equal to the current price.So the stack should keep smaller or equal prices and pop strictly smaller ones.
#while stack and prices[stack[-1]] <= prices[i]:
#    stack.pop()
def calculate_stock_span(prices):
    stack = []
    spans = []

    for i in range(len(prices)):
        # Correct condition: pop indices where price is less than or equal to current
        while stack and prices[stack[-1]] <= prices[i]:
            stack.pop()

        if not stack:
            span = i + 1
        else:
            span = i - stack[-1]

        spans.append(span)
        stack.append(i)

    return spans

