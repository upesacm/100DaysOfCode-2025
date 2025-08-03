def is_balanced(text):
    stack = []

    for char in text:
        if char == '(' or char == '{' or char == '[':
            stack.append(char)
        elif char == ')':
            if not stack or stack[-1] != '(':
                return False
            stack.pop()
        elif char == '}':
            if not stack or stack[-1] != '{':
                return False
            stack.pop()
        elif char == ']':
            if not stack or stack[-1] != '[':
                return False
            stack.pop()
          
    if not stack:
        return True
    else:
        return False
