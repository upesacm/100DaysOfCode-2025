def remove_adjacent_duplicates(s):
    stack = []
    for char in s:
        if stack and stack[-1] == char:
            stack.pop()
        else:
            stack.append(char)
    return ''.join(stack)

# Examples
print(remove_adjacent_duplicates("abbaca"))  # Output: "ca"
print(remove_adjacent_duplicates("azxxzy"))  # Output: "ay"
print(remove_adjacent_duplicates("aabcca"))  # Output: "b"
print(remove_adjacent_duplicates("a"))       # Output: "a"
print(remove_adjacent_duplicates("aa"))      # Output: ""
