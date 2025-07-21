def insert_at_bottom(stack, x):
    if not stack:
        stack.append(x)
    else:
        temp = stack.pop()
        insert_at_bottom(stack, x)
        stack.append(temp)

stack = list(input("Enter stack elements with space: ").split(','))
x = input("Enter element to insert at bottom: ")
insert_at_bottom(stack, x)
print(stack)