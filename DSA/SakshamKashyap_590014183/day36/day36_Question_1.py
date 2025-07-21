def reverse_string_with_stack(s):
    stack = []

    # Push all characters of the string onto the stack
    for char in s:
        stack.append(char)

    reversed_str = ""

    # Pop all characters from the stack and build the reversed string
    while stack:
        reversed_str += stack.pop()

    return reversed_str

# Test cases
print(reverse_string_with_stack("hello"))
print(reverse_string_with_stack("abcde"))
print(reverse_string_with_stack("CodeChallenge"))