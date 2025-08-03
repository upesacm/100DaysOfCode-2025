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

#line 6 is having bug in while stack and prices[stack[-1]] >= prices[i]: this code
#in the code of buggy line 6, the current logic was popping when previous price was greater than or equal — which removed valid span contributors.
#the correct condition should be while stack and prices[stack[-1]] <= prices[i]: