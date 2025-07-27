# 1. Bug Location

#    while stack and prices[stack[-1]] >= prices[i]:
#     stack.pop()

# 2.
# Expected:
# We want to pop elements that are smaller or equal to the current price.

# Current Code Pops:
# It pops when prices[stack[-1]] >= prices[i]
# That’s wrong, it pops greater prices, not smaller.

# When the current price is greater than previous lower prices, it still pops them — this disrupts the span logic. For example, with:
  
# prices = [100, 80, 60, 70, 60, 75, 85]
# At index 6 (price 85), it will pop 75, 60, 70, 60… (too many).

# The current code may overestimate the span, especially when the current price is large.

# 3. 
# We should pop only those days with prices less than or equal to current price, so the condition must be:

# while stack and prices[stack[-1]] <= prices[i]:
#     stack.pop()
  
# This way, only prices less than or equal are removed from consideration — the last higher price will remain to calculate the correct span.

# Correct Code

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
