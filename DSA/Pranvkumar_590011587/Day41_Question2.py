def decode_string(s: str) -> str:
    stack_num = []
    stack_str = []
    current_str = ""
    num = 0
    for ch in s:
        if ch.isdigit():
            num = num * 10 + int(ch)
        elif ch == '[':
            stack_num.append(num)
            stack_str.append(current_str)
            num = 0
            current_str = ""
        elif ch == ']':
            repeat = stack_num.pop()
            last_str = stack_str.pop()
            current_str = last_str + current_str * repeat
        else:
            current_str += ch

    return current_str

# Example Usage
print(decode_string("3[a]2[bc]"))       
print(decode_string("2[abc]3[cd]ef"))   