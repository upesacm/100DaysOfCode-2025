def insert_at_bottom(stack, x):
    if not stack:
        stack.append(x)
        return
    temp = stack.pop()
    insert_at_bottom(stack, x)
    stack.append(temp)

stack = list(map(int, input("Enter the number ").split()))#taking input from the user
x = int(input("Enter the element to insert at the bottom: "))
insert_at_bottom(stack, x)
print(stack)
#for example:-
# Input: 1 2 3 4
#x: 5
# Output: [5, 1, 2, 3, 4]
