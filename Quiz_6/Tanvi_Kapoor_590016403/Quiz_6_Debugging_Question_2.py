def calculate_stock_span(prices):
    # Task 1: Identify bug in stack condition
    # Original bug: stack was initialized as an integer (stack = 0), should be a list
    stack = []  # Correct initialization of stack

    # Bug: spans = I → typo; 'I' is not defined. Should be spans = []
    spans = []

    # Iterate through each day
    for i in range(len(prices)):

        # Task 2: Explain incorrect logic
        # Original logic tried: while stack and prices[stack[-1]] >= prices[i]
        # Bug: brackets were mismatched, and wrong condition
        # Incorrect logic: pops while previous prices are greater or equal
        # But for stock span, we want to pop while prices at stack top are **less than or equal**
        while stack and prices[stack[-1]] <= prices[i]:
            stack.pop()

        # If the stack is empty, it means all previous prices were smaller or equal
        if not stack:
            span = i + 1
        else:
            # Otherwise, the span is the difference between current index and top of stack
            span = i - stack[-1]

        spans.append(span)
        stack.append(i)  # Push current index to stack

    return spans

# Test case:
prices = [100, 80, 60, 70, 60, 75, 85]
result = calculate_stock_span(prices)
print(f"Stock spans: {result}")
# Expected Output: [1, 1, 1, 2, 1, 4, 6]
