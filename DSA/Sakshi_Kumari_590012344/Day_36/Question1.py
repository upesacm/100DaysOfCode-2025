def reverse_string_using_stack(text):
    stack = []

    for letter in text:
        stack.append(letter)

    reversed_text = ""

    while len(stack) > 0:
        reversed_text += stack.pop()

    return reversed_text

original_string = "hello"
print("Original String:", original_string)
print("Reversed String:", reverse_string_using_stack(original_string))
