def remove_adjacent_duplicates(s):
    stack = []
    for char in s:
        if stack and stack[-1] == char:
            stack.pop()  
        else:
            stack.append(char)
    return ''.join(stack)
print(remove_adjacent_duplicates("abbaca"))  
print(remove_adjacent_duplicates("azxxzy"))
