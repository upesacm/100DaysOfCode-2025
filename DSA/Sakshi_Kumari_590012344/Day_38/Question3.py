def has_redundant_brackets(expression):
    stack = []

    for letter in expression:
        if letter == ')':
            top = stack.pop()
            has_operator = False

            while top != '(':
                if top in '+-*/':
                    has_operator = True
                top = stack.pop()

            if not has_operator:
                return True
        else:
            stack.append(letter)

    return False
