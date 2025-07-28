"""
1. bug is: while stack and prices[stack[-1]] >= prices[i]:

2. The current logic pops greater than or equal elements, but we want to keep popping only smaller or equal elements

3. corrected condition: while stack and prices[stack[-1]] <= prices[i]:
"""

#corrected code: 
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

