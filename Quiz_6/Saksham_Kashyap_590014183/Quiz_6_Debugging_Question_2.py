# BUG: Condition 'prices[stack[-1]] >= prices[i]' pops higher/equal prices,
#      but for Stock Span, you must pop smaller/equal prices to properly extend your span.
#
# INCORRECT: while stack and prices[stack[-1]] >= prices[i]: stack.pop()
#      (Pops wrong entries, fails to count all previous <= prices)
#
# FIX: Use 'while stack and prices[stack[-1]] <= prices[i]:'.
#      (This groups all previous <= prices into the span, as needed.)
#
# RESULT: Now, for each day, the span is the correct count of consecutive
#      previous days that had a price <= today's price.

def calculate_stock_span(prices):
    stack = []  # stores indices of days, not prices
    spans = []

    for i in range(len(prices)):
        # FIX: pop all indices with prices <= current
        while stack and prices[stack[-1]] <= prices[i]:
            stack.pop()
        # Now, stack[-1] is the previous greater price (or stack is empty)

        # If stack empty, no greater price to left -> span is i+1
        if not stack:
            span = i + 1
        else:
            span = i - stack[-1]

        spans.append(span)
        # Push current index to stack
        stack.append(i)
    return spans

# --- TEST CASE (illustrating span computation step by step) ---
prices = [100, 80, 60, 70, 60, 75, 85]
# Expected: [1, 1, 1, 2, 1, 4, 6]
result = calculate_stock_span(prices)
print(f"Stock spans: {result}")
