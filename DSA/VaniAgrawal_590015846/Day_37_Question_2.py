# Use a stack to systematically process operands and operators in postfix notation for accurate mathematical expression evaluation
def evaluate_postfix(expression):
    stack = []
    for ch in expression:
        if ch.isdigit():
            stack.append(int(ch))
        else:
            b = stack.pop()
            a = stack.pop()
            if ch == '+':
                stack.append(a + b)
            elif ch == '-':
                stack.append(a - b)
            elif ch == '*':
                stack.append(a * b)
            elif ch == '/':
                stack.append(int(a / b))
    return stack[0]

expr = input("Enter postfix expression: ")
print("Result:", evaluate_postfix(expr))
