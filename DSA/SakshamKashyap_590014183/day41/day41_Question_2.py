def decode_string(s: str) -> str:
    count_stack = []
    string_stack = []
    current_string = ""
    k = 0
    
    for char in s:
        if char.isdigit():
            k = k * 10 + int(char)  # build the number, for numbers with multiple digits
        elif char == '[':
            # Push the count and the current string onto stacks
            count_stack.append(k)
            string_stack.append(current_string)
            # Reset for the new substring
            current_string = ""
            k = 0
        elif char == ']':
            count = count_stack.pop()
            previous_string = string_stack.pop()
            current_string = previous_string + current_string * count
        else:
            # Append current character to the current substring
            current_string += char
    
    return current_string

# Test cases
print(decode_string("3[a]2[bc]"))       # Output: "aaabcbc"
print(decode_string("2[abc]3[cd]ef"))   # Output: "abcabccdcdcdef"
