def has_redundant_brackets(expression):
    stack = []
    for char in expression:
        if char == ')':
            top = stack.pop()
            flag = True
            while top != '(':
                if top in '+-*/':
                    flag = False
                top = stack.pop()
            if flag:
                return "Yes"
        else:
            stack.append(char)
    return "No"

print(has_redundant_brackets("((a+b))"))
print(has_redundant_brackets("(a+b)"))
