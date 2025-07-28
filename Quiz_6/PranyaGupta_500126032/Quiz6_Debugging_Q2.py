#1. Bug is in the while condition on line 10
#2.It removes prices  greater than or equal to the current price, rather than removing prices that are less than or equal. As a result, it keeps higher prices on the stack, rather than lower prices.
#3. correct the line 10 condition -> while stack and prices[stack[-1]] <= prices[i]:

def calculate_stock_span(prices):
    stack = []
    spans = []

    for i in range(len(prices)):
        while stack and prices[stack[-1]] >= prices[i]:
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
