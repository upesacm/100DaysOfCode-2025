def is_balanced(expr):
    stack = []
    match = {')': '(', ']': '[', '}': '{'}
    for ch in expr:
        if ch in '([{':
            stack.append(ch)
        elif ch in ')]}':
            if not stack or stack[-1] != match[ch]:
                return False
            stack.pop()
    return len(stack) == 0

expr = input("Enter an expression: ")
print("Balanced" if is_balanced(expr) else "Not Balanced")
