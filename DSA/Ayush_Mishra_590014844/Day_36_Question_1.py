def reverse_string(s):
    stack = []
    for ch in s:
        stack.append(ch)
    return ''.join(stack[::-1])

s = input("Enter a string: ")
print("Reversed string:", reverse_string(s))
