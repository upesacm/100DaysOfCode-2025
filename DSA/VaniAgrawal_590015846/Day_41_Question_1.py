# Use a stack to systematically remove adjacent duplicate characters through iterative elimination until achieving a stable reduced string.
s = input("Enter the string: ")

while True:
    stack = []
    i = 0
    changed = False

    while i < len(s):
        if stack and stack[-1] == s[i]:
            stack.pop() 
            changed = True
        else:
            stack.append(s[i])
        i += 1

    new_s = ''.join(stack)
    if not changed:
        break 
    else:
        s = new_s 

print("Output:", new_s)
