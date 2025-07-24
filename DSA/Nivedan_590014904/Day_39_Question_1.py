def reverse(stack):
    if not stack:
        return   
    temp = stack.pop()
    reverse(stack)
    if not stack:
       stack.append(temp)
       return
    x = stack.pop()
    stack.append(temp)
    reverse(stack)
    stack.append(x)
stack = []
n = int(input("ENter the number of elements to be put in the stack: "))
for i in range(n):
    val = int(input(f"Input the {i+1} element: "))
    stack.append(val)
reverse(stack)
print(stack)
