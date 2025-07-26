num = input("Enter a number: ")#Take the input from the user 
k = int(input("Enter the number of digits to remove: "))
stack = []
for digit in num:
    while k and stack and stack[-1] > digit:
        stack.pop()
        k -= 1
    stack.append(digit)
while k:
    stack.pop()
    k -= 1
result = ''.join(stack).lstrip('0')
print(result if result else '0')
#for example:
# Input: "1432219", k = 3
# Output: "1219"