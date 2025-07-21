def insert_at_bottom(stack,x):
    
    if not stack:
        stack.append(x)
        return
    
    top=stack.pop()

    insert_at_bottom(stack,x)

    stack.append(top)

#example
stack=[50,51,52]
insert_at_bottom(stack,49)
print(stack)