def has_redundent_bracket(expression):
    stack=[]

    for char in expression:
        if char == ')':
            top = stack.pop()
            has_operator=False

            while top!='(':
                if top in '+-*/':
                    has_operator=True
                top=stack.pop()

            if not has_operator:
                return "Yes"
        
        else:
            stack.append(char)

    return "No"