def evaluate_postfix(expression):
    """
    Evaluates a postfix expression using a stack.
    """
    stack = []
    operators = set(['+', '-', '*', '/'])

    for char in expression:
        if char.isdigit():
            # Push numbers onto the stack
            stack.append(int(char))
        elif char in operators:
            # When an operator is found, pop the top two operands
            operand2 = stack.pop()
            operand1 = stack.pop()
            
            # Perform the operation and push the result back
            if char == '+':
                stack.append(operand1 + operand2)
            elif char == '-':
                stack.append(operand1 - operand2)
            elif char == '*':
                stack.append(operand1 * operand2)
            elif char == '/':
                # Integer division
                stack.append(int(operand1 / operand2))
    
    # The final result is the only item left on the stack
    return stack.pop()

# Test cases
print(evaluate_postfix("231*+9-"))
print(evaluate_postfix("52+"))
