def insert_at_bottom(stack,element):
    if not stack:
        stack.append(element)
        return
    top=stack.pop()
    insert_at_bottom(stack,element)
    stack.append(top)

def reverse_stack(stack):
    if not stack:
        return
    top=stack.pop()
    reverse_stack(stack)
    insert_at_bottom(stack,top)
    