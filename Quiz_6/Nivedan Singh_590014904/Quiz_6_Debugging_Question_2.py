def calculate_stock_span(prices):
    stack = []
    spans = []

    for i in range(len(prices)):
        while stack and prices[stack[-1]] <= prices[i]:#Here it was >= which is the wrong operator to use in this case as we want to count the previous days it was lesser than and equal to todays price.
#So in the above code we added the correct condition of <= instead of >=
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
# It used to return [1, 2, 3, 1, 5, 1, 1]
