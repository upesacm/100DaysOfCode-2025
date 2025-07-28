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
# # What does it actually return?


#Task Answer:
# 1. Identify the bug in the stack condition:
# -The condition while stack and prices[stack[-1]] >= prices[i]: is incorrect.
# 2. Explain what the current logic does incorrectly:
# -It pops prices that are greater than or equal to the current price, which is the reverse of what stock span requires.
# -This logic results in undercounting the span when previous prices are less than or equal to the current price — the correct definition of span.
# 3. What should the correct condition be?
# -The correct condition should be: while stack and prices[stack[-1]] <= prices[i]:
# -This ensures we keep removing indices with prices less than or equal to the current day's price,
#  so we can calculate how many such days exist before the current one.
