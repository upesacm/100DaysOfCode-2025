prices = list(map(int, input("Eneter the number:").split()))#Taking input from the user 
n = len(prices)
span = [0] * n
stack = []

for i in range(n):
    while stack and prices[stack[-1]] <= prices[i]:
        stack.pop()
    if not stack:
        span[i] = i + 1
    else:
        span[i] = i - stack[-1]
    stack.append(i)
print(span)
# Example usage:
# Input: 100 80 60 70 60 75 85
# Output: [1, 1, 1, 2, 1, 4, 6]