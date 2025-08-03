post = input("Enter the experssion in postfix format seprated by space: ").split()
stack = []
for element in post:
    if element.isdigit():
        stack.append(int(element))
    else:
        b = stack.pop()
        a = stack.pop()
        if element == "+":
            stack.append(a+b)
        elif element == "-":
            stack.append(a-b)
        elif element == "*":
            stack.append(a*b)
        elif element == "/":
            stack.append(a/b)
print(stack[0])
