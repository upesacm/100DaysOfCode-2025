# Implement a sorting algorithm using only stack operations and one additional stack as temporary storage for efficient data organization
def sort_stack(stack):
    temp_stack = []
    while stack:
        temp = stack.pop()
        while temp_stack and temp_stack[-1] > temp:
            stack.append(temp_stack.pop())
        temp_stack.append(temp)
    return temp_stack

stack = list(map(int, input("Enter stack elements (space separated): ").split()))
print("Sorted Stack:", sort_stack(stack))
