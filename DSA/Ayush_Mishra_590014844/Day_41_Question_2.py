def decode_string(s):
    stack = []
    current_string = ''
    k = 0

    for ch in s:
        if ch.isdigit():
            k = k * 10 + int(ch)
        elif ch == '[':
            stack.append((current_string, k))
            current_string, k = '', 0
        elif ch == ']':
            prev_string, repeat = stack.pop()
            current_string = prev_string + current_string * repeat
        else:
            current_string += ch
    return current_string

s = input("Enter the encoded string: ")
print(decode_string(s))
