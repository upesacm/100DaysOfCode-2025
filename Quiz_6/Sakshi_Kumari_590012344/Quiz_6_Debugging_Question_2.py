1. Identify the bug in the stack condition 
This line is wrong:
while stack and prices[stack[-1]] >= prices[i]:

2. Explain what the current logic does incorrectly 
The current logic is popping the days where the price is higher, but keeping the smaller prices in the stack.
That’s the opposite of what we actually want. Because of this, the code fails to count all the days where the price was less than or equal to the current day’s price. 
So, the span values come out smaller than they should be—especially when prices go up after a few lower ones.

3. What should the correct condition be?
This is the correct fix:
while stack and prices[stack[-1]] <= prices[i]:

Here is the corrected code:-
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

