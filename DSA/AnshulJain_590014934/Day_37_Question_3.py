def delete_middle(stack, current, size):
    if current == size // 2:
        stack.pop()
        return
    temp = stack.pop()
    delete_middle(stack, current + 1, size)
    stack.append(temp)
stack = list(map(int, input("Enter the number:").split()))#Taking input from user
delete_middle(stack, 0, len(stack))
print(*stack)
#for example:
#Input: 1 2 3 4 5
#Output: 1 2 4 5
