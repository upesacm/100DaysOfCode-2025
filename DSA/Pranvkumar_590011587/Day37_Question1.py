def sort_stack(input_stack):
    aux_stack = []
    while input_stack:
        temp = input_stack.pop()
        while aux_stack and aux_stack[-1] > temp:
            input_stack.append(aux_stack.pop())
        aux_stack.append(temp)
    # Optional: Transfer back to input_stack for sorted order with smallest on top
    while aux_stack:
        input_stack.append(aux_stack.pop())
    return input_stack

# Examples:
print(sort_stack([3, 1, 4, 2])) 
print(sort_stack([6, 5, 8])) 