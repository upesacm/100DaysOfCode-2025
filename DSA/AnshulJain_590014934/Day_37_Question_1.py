def sort_stack(input_stack):
    temp_stack = []
    while input_stack:
        temp = input_stack.pop()
        while temp_stack and temp_stack[-1] > temp:
            input_stack.append(temp_stack.pop())
        temp_stack.append(temp)
    return temp_stack
stack = list(map(int, input("Enter the number:").split()))#taing input from user
sorted_stack = sort_stack(stack)
print(*sorted_stack)
#for example:
#Input: 34 3 31 98 92
#Output: 3 31 34 92 98
