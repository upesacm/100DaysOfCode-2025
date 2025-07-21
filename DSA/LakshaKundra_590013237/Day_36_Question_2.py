def is_balanced(s):
    stack = []
    mapping = {')': '(', '}': '{', ']': '['}
    for char in s:
        if char in mapping.values():
            stack.append(char)
        elif char in mapping:
            if not stack or stack.pop() != mapping[char]:
                return "Not Balanced"
    return "Balanced" if not stack else "Not Balanced"

print(is_balanced("([])"))
print(is_balanced("(["))
