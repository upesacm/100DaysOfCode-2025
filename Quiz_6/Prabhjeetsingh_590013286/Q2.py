#2. Why this causes incorrect behavior:
#The pop() function removes elements from self.stack, but does not update self.min_val when the minimum value is removed.
#self.min_val is only updated during push(), so once the actual minimum is popped, the old min value remains.
#This causes get_min() to return incorrect results after popping the minimum.
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

