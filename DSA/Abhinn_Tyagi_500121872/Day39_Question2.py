def calculate_span(prices):
    span = [0] * len(prices)
    stack = [] 

    for i in range(len(prices)):
        while stack and prices[stack[-1]] <= prices[i]:
            stack.pop()
        span[i] = i + 1 if not stack else i - stack[-1]
        stack.append(i)
    
    return span

print("Stock Span:", calculate_span([100, 80, 60, 70, 60, 75, 85]))

print("Stock Span:", calculate_span([10, 20, 30]))

