# Solution of question 2
def calculate_stock_span(prices):
    stack = []
    spans = []

    for i in range(len(prices)):
        # BUG: `prices[stack[-1]] >= prices[i]` is incorrect
        # FIX: We want to remove *strictly smaller or equal* prices
        while stack and prices[stack[-1]] <= prices[i]:
            stack.pop()

        # Span calculation remains the same
        if not stack:
            span = i + 1
        else:
            span = i - stack[-1]

        spans.append(span)
        stack.append(i)

    return spans

#Task 1:
# Bug Summary:
# Buggy condition: `while stack and prices[stack[-1]] >= prices[i]`

#Task 2: 
# Why it's wrong:
#     - It pops *larger* prices instead of smaller/equal ones
#     - This reverses the logic — span becomes inaccurate

# Correct condition: `prices[stack[-1]] <= prices[i]`
#     - This ensures we track all **previous smaller or equal** prices for correct span
