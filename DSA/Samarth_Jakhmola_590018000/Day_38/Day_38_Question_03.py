def redundant_brackets(expression):
    stack = []

    for char in expression:
        if char == ')':
            top = stack.pop()
            has_operator = False
            
            while top != '(':
                if top in "+-*/":
                    has_operator = True
                top = stack.pop()
                
            if not has_operator:
                return True
        else:
            stack.append(char)

    return False

try:
    expression = input("Enter the expression : ")
    print("Yes" if redundant_brackets(expression) else "No")
except:
    print("Invalid input. Please try with a valid input.")
