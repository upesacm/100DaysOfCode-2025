def decode_string(s):
    count_stack=[]
    string_stack=[]
    current_str=' '
    k=0

    for char in s:
        if char.isdigit():
            k=k*10 + int(char)
        elif char == '[':
            count_stack.append(k)
            string_stack.append(current_str)
            current_str=''
            k=0
        elif char == ']':
            repeat=count_stack.pop()
            prev_str=string_stack.pop()
            current_str=prev_str + current_str*repeat
        else:
            current_str += char

    return current_str

#example
print(decode_string("3[a]2[bc]"))