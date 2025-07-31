def insert_at_bottom(stack, item):
    if not stack:
        stack.append(item)
        return
    temp = stack.pop()
    insert_at_bottom(stack, item)
    stack.append(temp)
def reverse_stack(stack):
    if stack:
        temp = stack.pop()
        reverse_stack(stack)
        insert_at_bottom(stack, temp)
stack = list(map(int, input("Enter the number:").split()))#taking input from the user 
reverse_stack(stack)
print(stack)
#for example:
# Input: 1 2 3 4 5
# Output: [5, 4, 3, 2, 1]