 # Error 
# while stack and prices[stack[-1]] >= prices[i]:

# 🔍 What's wrong?
# The condition is removing prices greater than or equal to the current price.
# But in the stock span problem, we should remove prices that are less than or equal, 
# because we want to count all previous smaller or equal values.
# So you're popping useful values that should be included in the span calculation.


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
