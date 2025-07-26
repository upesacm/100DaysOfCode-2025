#Use a monotonic stack with greedy selection to remove k digits while building the lexicographically smallest possible number.
num = input("Enter the number string: ")
k = int(input("Enter the value of k (digits to remove): "))

stack = []

for digit in num:
    while k > 0 and stack and stack[-1] > digit:
        stack.pop()
        k -= 1
    stack.append(digit)

while k > 0:
    stack.pop()
    k -= 1

result = ''.join(stack).lstrip('0')

print(result if result else "0")
