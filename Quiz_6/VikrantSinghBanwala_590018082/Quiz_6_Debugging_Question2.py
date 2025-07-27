'''1. bug in
while stack and prices[stack[-1]] >= prices[i]:
2.current logic removes prices that are equal to current price, which should not happen. 
This causes function to give wrong span values for days when price is same as previous days price.
3.corect condition:
while stack and prices[stack[-1]] < prices[i]:

correct code:'''
def calculate_stock_span(prices):
    stack = []
    spans = []

    for i in range(len(prices)):
        while stack and prices[stack[-1]] < prices[i]: 
            stack.pop()

        if not stack:
            span = i + 1
        else:
            span = i - stack[-1]

        spans.append(span)
        stack.append(i)

    return spans
