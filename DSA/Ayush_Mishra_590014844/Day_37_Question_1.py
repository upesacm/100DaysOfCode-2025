def sort_stack(stack):
    temp_stack = []
    while stack:
        temp = stack.pop()
        while temp_stack and temp_stack[-1] > temp:
            stack.append(temp_stack.pop())
        temp_stack.append(temp)
    return temp_stack[::-1]

stack = list(map(int, input().split()))
sorted_stack = sort_stack(stack)
print(*sorted_stack)
