# 3. Insert at Bottom of Stack
def insert_at_bottom(stack: list, item: any):
    """
    Recursively inserts an element at the bottom of a stack.

    This function uses recursion to hold all elements in the call stack,
    inserts the new item when the stack is empty, and then pushes the
    held elements back on top.

    Args:
        stack: The stack (as a list) to be modified.
        item: The item to insert at the bottom.
    """
    if not stack:
        stack.append(item)
    else:
        temp = stack.pop()
        insert_at_bottom(stack, item)
        stack.append(temp)

if __name__ == "__main__":
    stack1 = [1, 2, 3]
    item1 = 0
    print(f"Input Stack: {stack1}, Item: {item1}")
    insert_at_bottom(stack1, item1)
    print(f"Output Stack: {stack1}") 
    stack2 = [5, 6]
    item2 = 9
    print(f"\nInput Stack: {stack2}, Item: {item2}")
    insert_at_bottom(stack2, item2)
    print(f"Output Stack: {stack2}")  