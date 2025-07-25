def calculate_span(price):
    n = len(price)
    span = [0] * n
    stack = []
    for i in range(n):
        while stack and price[stack[-1]] <= price[i]:
            stack.pop()
        if not stack:
            span[i] = i+1
        else:
            span[i] = i - stack[-1]
        

        stack.append(i)
    return span

print(calculate_span([100, 80, 60, 70, 60, 75, 85]))
print(calculate_span([10, 20, 30]))


