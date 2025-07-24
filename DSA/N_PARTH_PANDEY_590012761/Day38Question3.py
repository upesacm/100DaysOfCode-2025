def has_redundant_brackets(expression):
    stack = []
    
    for char in expression:
        if char == ')':
            has_operator = False
            while stack and stack[-1] != '(':
                top = stack.pop()
                if top in '+-*/':
                    has_operator = True
            
            if not stack:
                return True
            
            stack.pop()
            
            if not has_operator:
                return True
        else:
            stack.append(char)
    
    return False


if __name__ == "__main__":
    print("Enter mathematical expressions to check for redundant brackets (or 'exit' to quit):")
    while True:
        expr = input("> ").strip()
        if expr.lower() == 'exit':
            break
        
        if not expr:
            continue
        
        result = has_redundant_brackets(expr)
        print("Yes" if result else "No")