def middle(stack,current ,n):
    if current == n//2:
        stack.pop()
        return
    temp = stack.pop()
    middle(stack,current+1,n)
    stack.append(temp)
stack = []
n = int(input("ENter the number of elements to be put in the stack: "))
for i in range(n):
    val = int(input(f"Input the {i+1} element: "))
    stack.append(val)
middle(stack,0,n)
print(stack)
