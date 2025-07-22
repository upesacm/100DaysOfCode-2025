def is_balanced(s):
    stack = []
    bracket_map = {")": "(", "}": "{", "]": "["}

    for char in s:
        if char in bracket_map.values():
            stack.append(char)
        elif char in bracket_map.keys():
            if not stack or stack.pop() != bracket_map[char]:
                return "Not Balanced"
    
    if not stack:
        return "Balanced"
    else:
        return "Not Balanced"

# Test cases
print(is_balanced("([])"))
print(is_balanced("([)]"))
print(is_balanced("(["))
print(is_balanced("{[()]}"))