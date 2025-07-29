# 1. Identify the bug in the stack condition
# -- while stack and prices[stack[-1]] >= prices[i]:
#    stack.pop()

# 2. Explain what the current logic does incorrectly 
# -- The condition prices[stack[-1]] >= prices[i] pops elements with prices greater than or equal to the current price.
# --But the stock span is defined as the number of consecutive previous days with prices less than or equal to the current price.
# --So we should retain days with lower or equal prices, and remove only those with higher prices.

#3. What should the correct condition be?
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
prices = [100, 80, 60, 70, 60, 75, 85]
print(calculate_stock_span(prices))  # ➜ [1, 1, 1, 2, 1, 4, 6]
