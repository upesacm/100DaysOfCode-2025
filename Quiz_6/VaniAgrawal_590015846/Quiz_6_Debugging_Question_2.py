#Bug :
#The while condition is wrong: it pops when prices[stack[-1]] >= prices[i].
#It should pop when prices[stack[-1]] <= prices[i], as we want to count days with lesser or equal price.
# correct code
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
