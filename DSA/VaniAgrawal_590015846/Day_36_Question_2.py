#Use a stack to track opening brackets and validate proper pairing with closing brackets for complete balance verification. 
def is_balanced():
    s = input("Enter a string with brackets: ")
    stack = []
    mapping = {')': '(', ']': '[', '}': '{'}
    
    for char in s:
        if char in '([{':
            stack.append(char)
        elif char in mapping:
            if not stack or stack[-1] != mapping[char]:
                print("Not Balanced")
                return
            stack.pop()
    
    if not stack:
        print("Balanced")
    else:
        print("Not Balanced")

is_balanced()
