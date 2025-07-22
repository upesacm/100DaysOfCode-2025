def insert_at_bottom(stack, x):
    if not stack:
        stack.append(x)
        return
    top = stack.pop()
    insert_at_bottom(stack, x)
    stack.append(top)

n = int(input("Enter number of elements: "))
stack = list(map(int, input("Enter stack elements (top to bottom): ").split()))
x = int(input("Enter element to insert at bottom: "))
insert_at_bottom(stack, x)
print("Stack after insertion (bottom to top):", stack)
