def decode_string(s):
    stack = []
    curr_num = 0
    curr_str = ''
    for char in s:
        if char.isdigit():
            curr_num = curr_num * 10 + int(char)
        elif char == '[':
            stack.append((curr_str, curr_num))
            curr_str = ''
            curr_num = 0
        elif char == ']':
            prev_str, num = stack.pop()
            curr_str = prev_str + curr_str * num
        else:
            curr_str += char
    return curr_str

# Examples
print(decode_string("3[a]2[bc]"))        # Output: "aaabcbc"
print(decode_string("2[abc]3[cd]ef"))    # Output: "abcabccdcdcdef"
print(decode_string("10[a]"))            # Output: "aaaaaaaaaa"
print(decode_string("3[a2[c]]"))         # Output: "accaccacc"
print(decode_string("2[ab3[c]]"))        # Output: "abcccabccc"
