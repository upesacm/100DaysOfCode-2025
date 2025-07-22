def insert_at_bottom(stack, item):
    """
    Recursively inserts an item at the bottom of a stack.
    """
    if not stack:
        stack.append(item)
    else:
        temp = stack.pop()
        insert_at_bottom(stack, item)
        stack.append(temp)

# --- Test cases ---

# Example 1
stack1 = [1, 2, 3]
item1 = 0
insert_at_bottom(stack1, item1)
print(stack1)  # Expected output: [0, 1, 2, 3]

# Example 2
stack2 = [5, 6]
item2 = 9
insert_at_bottom(stack2, item2)
print(stack2)  # Expected output: [9, 5, 6]