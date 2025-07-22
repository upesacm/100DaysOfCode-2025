def insert_at_bottom(stack, x):
    if not stack:
        stack.append(x)
    else:
        top = stack.pop()
        insert_at_bottom(stack, x)
        stack.append(top)

stack1 = [1, 2, 3]
insert_at_bottom(stack1, 0)
print(stack1)

stack2 = [5, 6]
insert_at_bottom(stack2, 9)
print(stack2)
