1.
Bug:
while stack and prices[stack[-1]] >= prices[i]:

2. What the current logic does incorrectly:
The stock span is defined as the number of consecutive days (including today) where the price was less than or equal to today's price.

But the current condition removes equal prices as well. That means it doesn't count previous equal-priced days as part of the span — which is wrong

Correct Stack Condition:
while stack and prices[stack[-1]] <= prices[i]:  
This removes all indices of previous prices that are less than or equal to the current price, which allows us to compute the span correctly.

code:
def calculate_stock_span(prices):
    stack = []
    spans = []

    for i in range(len(prices)):
        # Correct condition: remove smaller or equal elements
        while stack and prices[stack[-1]] <= prices[i]:
            stack.pop()

        if not stack:
            span = i + 1
        else:
            span = i - stack[-1]

        spans.append(span)
        stack.append(i)

    return spans
