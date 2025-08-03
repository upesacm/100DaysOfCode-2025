def delete_middle(stack, current, middle):
    if current == middle:
        stack.pop()
        return

    temp = stack.pop()
    delete_middle(stack, current + 1, middle)
    stack.append(temp)

def remove_middle(stack):
    size = len(stack)
    mid = size // 2
    delete_middle(stack, 0, mid)
