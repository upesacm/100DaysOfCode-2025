Task
1. Identify the bug in the stack condition 
2. Explain what the current logic does incorrectly 
3. What should the correct condition be?

TASK 1
while stack and prices[stack[-1]] >= prices[i]:
    stack.pop()

TASK 2
This logic pops prices from the stack that are greater than or equal to the current price. 
But stock span is about counting previous prices that are less than or equal to the current one. So this code is incorrectly removing prices that we should be counting toward the span.

TASK 3
def calculate_stock_span(prices):
    stack = []
    spans = []

    for i in range(len(prices)):
        while stack and prices[stack[-1]] <= prices[i]:  # ✅ Corrected condition
            stack.pop()

        if not stack:
            span = i + 1
        else:
            span = i - stack[-1]

        spans.append(span)
        stack.append(i)

    return spans
Footer
