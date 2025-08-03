def has_redundant(expr):
    stack = []
    for ch in expr:
        if ch == ')':
            if stack.pop() == '(':
                return True
            while stack.pop() != '(':
                continue
        else:
            stack.append(ch)
    return False

expr = input("Enter expression: ")
print("Yes" if has_redundant(expr) else "No")
