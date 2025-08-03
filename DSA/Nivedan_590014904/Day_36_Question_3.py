stack = []
n = int(input("ENter the number of elements to be put in the stack: "))
for i in range(n):
    val = int(input(f"Input the {i+1} element: "))
    stack.append(val)
x = int(input("The value of x: "))
new = []
while stack:
    new.append(stack.pop())
stack.append(x)
while new:
    stack.append(new.pop())
print(stack)
