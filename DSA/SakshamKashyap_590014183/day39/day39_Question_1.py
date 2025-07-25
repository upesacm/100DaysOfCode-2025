def insert_at_bottom(stack,item):
    if not stack:
        stack.append(item)
        return
    temp = stack.pop()
    insert_at_bottom(stack,item)
    stack.append(temp)

def reverse_stack(stack):
    if stack:
        temp = stack.pop()
        reverse_stack(stack)
        insert_at_bottom(stack,temp)

#test Case
stack1 = [1, 2, 3]
reverse_stack(stack1)
print(stack1)

stack2 = [5,6]
reverse_stack(stack2)
print(stack2)


