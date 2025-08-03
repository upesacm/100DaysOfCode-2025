def calculate_span(prices):
    stack = []  # stores indices
    span = [0] * len(prices)
    for i in range(len(prices)):
        while stack and prices[stack[-1]] <= prices[i]:
            stack.pop()
        span[i] = i + 1 if not stack else i - stack[-1]
        stack.append(i)
    return span

# Examples
print("Span 1:", calculate_span([100, 80, 60, 70, 60, 75, 85]))  
print("Span 2:", calculate_span([10, 20, 30]))                 