def evaluate_postfix(expression):
    stack = []
    for token in expression:
        if token.isdigit():
            stack.append(int(token))
        elif len(stack) >= 2:
            b = stack.pop()
            a = stack.pop()
            if token == '+':
                stack.append(a + b)
            elif token == '-':
                stack.append(a - b)
            elif token == '*':
                stack.append(a * b)
            elif token == '/':
                stack.append(int(a / b))
    return stack[0]
expression = input("Enter a postfix expression: ") #taking input from user
result = evaluate_postfix(expression)
print(result)
#for example:
#Input:231*+9-
#Output:-4
