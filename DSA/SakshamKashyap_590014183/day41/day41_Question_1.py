def remove_adjacent_duplicates(s: str) -> str:
    while True:
        stack = []
        changed = False
        i = 0
        
        while i < len(s):
            if stack and stack[-1] == s[i]:
                # Skip all adjacent duplicates
                while i < len(s) and stack[-1] == s[i]:
                    i += 1
                stack.pop()  # remove the duplicate character
                changed = True
            else:
                stack.append(s[i])
                i += 1
        
        new_s = ''.join(stack)
        if not changed:
            return new_s
        s = new_s

# Test examples
print(remove_adjacent_duplicates("abbaca"))  # Output: "ca"
print(remove_adjacent_duplicates("azxxzy"))  # Output: "ay"
