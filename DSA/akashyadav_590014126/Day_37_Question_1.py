def sort_by_stack(input_stack):
    temp_stack=[]

    while input_stack:
        curr=input_stack.pop()

        while temp_stack and temp_stack[-1] > curr:
            input_stack.append(temp_stack.pop())

        temp_stack.append(curr)

    while temp_stack:
        input_stack.append(temp_stack.pop())
    return input_stack[::-1]

#example

print(sort_by_stack([4,3,1,2]))