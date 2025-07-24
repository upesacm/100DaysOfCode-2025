def sort_stack(input_stack):
    temp_stack = []
    while input_stack:
        temp = input_stack.pop()
        while temp_stack and temp_stack[-1] > temp:
            input_stack.append(temp_stack.pop())
        temp_stack.append(temp)
    return temp_stack

input_str = input("Enter the stack elements separated by spaces: ")
input_list = list(map(int, input_str.split()))
sorted_stack = sort_stack(input_list)
print(sorted_stack)