def has_redundant_brackets(expr):
    stack = []
    for char in expr:
        if char == ')':
            top = stack.pop()
            elements_inside = 0
            while top != '(':
                if top in '+-*/':
                    elements_inside += 1
                top = stack.pop()
            if elements_inside == 0:
                return "Yes"
        else:
            stack.append(char)
    return "No"

# Examples
print(has_redundant_brackets("((a+b))"))  
print(has_redundant_brackets("(a+b)"))    