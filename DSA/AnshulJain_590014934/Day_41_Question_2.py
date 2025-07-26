string= input("Enter a string with digits and brackets: ")  # Taking input from the user
stack = []
num = ''
for ch in string:
    if ch.isdigit():
        num += ch
    elif ch == '[':
        stack.append(int(num))
        num = ''
        stack.append('')
    elif ch == ']':
        substr = stack.pop()
        count = stack.pop()
        if stack and isinstance(stack[-1], str):
            stack[-1] += substr * count
        else:
            stack.append(substr * count)
    else:
        if stack and isinstance(stack[-1], str):
            stack[-1] += ch
        else:
            stack.append(ch)
print(''.join(stack))
#for example:
# Input: "3[a2[c]]"
# Output: "accaccacc"