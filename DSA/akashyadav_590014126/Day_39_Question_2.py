def calculate_span(prices):
    n=len(prices)
    span=[0]*n
    stack=[]

    for i in range(n):
        while stack and prices[stack[-1]] <= prices[i]:
            stack.pop()

        if not stack:
                span[i]=i+1
        else:
                span[i]=i-stack[-1]

        stack.append(i)
    return span