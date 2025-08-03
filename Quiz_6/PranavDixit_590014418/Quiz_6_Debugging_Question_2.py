def calculate_stock_span(prices):
    stack = []
    spans = []
    for i in range(len(prices)):
        # Correction: the stack condition should be <=, not >=
        while stack and prices[stack[-1]] <= prices[i]:
            stack.pop()
        if not stack:
            span = i + 1
        else:
            span = i - stack[-1]
        spans.append(span)
        stack.append(i)
    return spans

# Test case
prices = [100, 80, 60, 70, 60, 75, 85]
result = calculate_stock_span(prices)
print(f"Stock spans: {result}")  # Should print: [1, 1, 1, 2, 1, 4, 6]



# 1. The bug is in the limiting stack condition: 
#    it used >= instead of <=
#
# 2. With >=, the code would pop past equal or strictly higher prices, 
#    giving wrong span answers for increasing prices.
#
# 3. The correct condition for the stock span problem is:
#    while stack and prices[stack[-1]] <= prices[i]:
#        stack.pop()
#
#    This way, the stack always contains indices of prices that are strictly larger
#    and lets us calculate the correct span for each day.
