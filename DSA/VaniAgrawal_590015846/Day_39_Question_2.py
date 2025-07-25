# Use a monotonic stack to efficiently compute stock price spans by tracking previous higher prices for optimal time-series analysis.
prices = list(map(int, input("Enter stock prices separated by space: ").strip().split()))

stack = []
span = []

for i in range(len(prices)):
   
    while stack and prices[stack[-1]] <= prices[i]:
        stack.pop()
    
    if not stack:
        span.append(i + 1)
    else:
        span.append(i - stack[-1])
    
    stack.append(i)

print("Span values:")
print(span)
