def evaluate_postfix(expression):
    stack = []

    for char in expression:
        if char.isdigit():
            stack.append(int(char))
        else:
            right = stack.pop()
            left = stack.pop()

            if char == '+':
                stack.append(left + right)
            elif char == '-':
                stack.append(left - right)
            elif char == '*':
                stack.append(left * right)
            elif char == '/':
                stack.append(int(left / right))
            else:
                raise ValueError(f"Unsupported operator : {char}")
            
    return stack.pop()

try:
    expression = input("Enter the expression : ")
    print(evaluate_postfix(expression))
except:
    print("Invalid input. Please try with a valid input.")
