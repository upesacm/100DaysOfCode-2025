def evaluate_postfix(expression):
    stack = []
    for char in expression:
        if char.isdigit():
            stack.append(int(char))
        else:
            b = stack.pop()
            a = stack.pop()
            if char == '+':
                stack.append(a + b)
            elif char == '-':
                stack.append(a - b)
            elif char == '*':
                stack.append(a * b)
            elif char == '/':
                stack.append(int(a / b))
    return stack[0]

print(evaluate_postfix("231*+9-"))  # Output: -4
print(evaluate_postfix("52+"))      # Output: 7
