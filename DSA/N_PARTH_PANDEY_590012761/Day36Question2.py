def is_balanced(s):
    stack = []
    mapping = {')': '(', '}': '{', ']': '['}
    for char in s:
        if char in mapping.values():
            stack.append(char)
        elif char in mapping.keys():
            if not stack or stack.pop() != mapping[char]:
                return False
    return not stack

user_input = input("Enter a string to check for balanced parentheses: ")
print("Balanced" if is_balanced(user_input) else "Not Balanced")