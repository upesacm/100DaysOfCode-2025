# Use stack-based parsing to identify redundant bracket pairs by tracking operators and operands within parentheses for optimization detection.
expr = input("Enter a mathematical expression: ")

def has_redundant_brackets(expression):
    stack = []
    for ch in expression:
        if ch == ')':
            top = stack.pop()
            elements_inside = 0
            while top != '(':
                elements_inside += 1
                top = stack.pop()
            if elements_inside <= 1:
                return True
        else:
            stack.append(ch)
    return False

print("Output:")
print("Yes" if has_redundant_brackets(expr) else "No")
