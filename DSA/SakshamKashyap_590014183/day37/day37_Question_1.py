def sort_stack(input_stack):
    """
    Sorts a stack using another temporary stack.
    """
    temp_stack = []

    while input_stack:
        # Pop out the first element
        temp_val = input_stack.pop()

        # While temporary stack is not empty and top
        # of temp_stack is greater than temp_val
        while temp_stack and temp_stack[-1] > temp_val:
            # Pop from temporary stack and push it to the input stack
            input_stack.append(temp_stack.pop())
        
        # Push temp_val to temporary stack
        temp_stack.append(temp_val)

    return temp_stack
print(sort_stack([3, 1, 4, 2]))
print(sort_stack([6, 5, 8]))