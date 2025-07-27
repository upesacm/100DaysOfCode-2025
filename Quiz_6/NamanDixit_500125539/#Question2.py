#1. Error -> while stack and prices[stack[-1]] >= prices[i]:
#2. Correct logic -> The current condition pops higher or equal values.

#But we should be popping smaller or equal values, because:

#We are trying to find the number of consecutive days before the current day where the price was less than or equal to today's price.

#he code as written treats lower prices as obstacles, which is opposite of what's required.
#3. Corrected code
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
# Expected: [1, 1, 1, 2, 1, 4, 6]
# What does it actually return?
