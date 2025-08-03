def delete_mid(stack,curr_index=0,size=None):
    if size is None:
        size=len(stack)

    if curr_index == size//2:
        stack.pop()
        return
    temp=stack.pop()

    delete_mid(stack,curr_index+1,size)

    stack.append(temp)

#example
stack=[40,41,42,43,45,46]
delete_mid(stack)
print(stack)