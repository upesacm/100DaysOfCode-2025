def reverse_by_stack(s):
    stack=[]

    for char in s:
        stack.append(char)

    reversed_str=""
    while stack:
        reversed_str += stack.pop()

    return reversed_str

#example
print(reverse_by_stack("Python"))