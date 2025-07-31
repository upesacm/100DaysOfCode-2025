expression = input()
stack = []
redundant = False

for ch in expression:
    if ch == ')':
        top = stack.pop()
        elements_inside = 0
        while top != '(':
            elements_inside += 1
            top = stack.pop()
        if elements_inside <= 1:
            redundant = True
            break
    else:
        stack.append(ch)

if redundant:
    print("Yes")
else:
    print("No")
#for example :
# Input: (a + b)
# Output: No
