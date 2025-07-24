def min_stack(stack):
    if not stack:
        return None
    min_val = stack.pop()
    while stack:
        current_element = stack.pop()
        if current_element < min_val:
            min_val = current_element
    return min_val
#test Cases
print(min_stack([5,3,7]))
print(min_stack([10, 2, 9, 1, 15]))