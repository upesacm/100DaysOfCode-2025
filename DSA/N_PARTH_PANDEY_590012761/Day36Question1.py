def reverse_string(s):
    stack = []
    for char in s:
        stack.append(char)
    reversed_str = []
    while stack:
        reversed_str.append(stack.pop())
    return ''.join(reversed_str)

user_input = input("Enter any string: ")
print(reverse_string(user_input))