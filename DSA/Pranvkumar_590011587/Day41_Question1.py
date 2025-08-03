def remove_adjacent_duplicates(s: str) -> str:
    while True:
        stack = []
        i = 0
        while i < len(s):
            if stack and stack[-1] == s[i]:
                stack.pop()  
            else:
                stack.append(s[i])
            i += 1
        new_s = ''.join(stack)
        if new_s == s:  
            break
        s = new_s
    return s

# Example Usage
print(remove_adjacent_duplicates("abbaca")) 
print(remove_adjacent_duplicates("azxxzy"))  