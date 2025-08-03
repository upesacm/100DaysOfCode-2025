def find_redundant_brackets(expression):
    stack = []
    operators = {'+', '-', '*', '/'}

    for char in expression:
        if char == ')':
            is_redundant = True
            
            while stack and stack[-1] != '(':
                if stack.pop() in operators:
                    is_redundant = False
            
            stack.pop()
            if is_redundant:
                return "Yes"
        
        elif char == '(' or char in operators:
            stack.append(char)
            
    return "No"

# Test cases
print(find_redundant_brackets("((a+b))"))
print(find_redundant_brackets("(a+b)"))
