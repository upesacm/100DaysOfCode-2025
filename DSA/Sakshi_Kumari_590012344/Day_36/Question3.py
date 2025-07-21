def insert_at_bottom(stack, value):
    if not stack:
        stack.append(value)
        return

    top = stack.pop()
    insert_at_bottom(stack, value)
    stack.append(top)
