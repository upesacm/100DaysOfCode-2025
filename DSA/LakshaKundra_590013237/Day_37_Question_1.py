def sort_stack(stack):
    temp_stack = []
    while stack:
        temp = stack.pop()
        while temp_stack and temp_stack[-1] > temp:
            stack.append(temp_stack.pop())
        temp_stack.append(temp)
    while temp_stack:
        stack.append(temp_stack.pop())
    return stack

print(sort_stack([3, 1, 4, 2]))
print(sort_stack([6, 5, 8]))
