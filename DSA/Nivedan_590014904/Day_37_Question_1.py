stack = []
n = int(input("ENter the number of elements to be put in the stack: "))
for i in range(n):
    val = int(input(f"Input the {i+1} element: "))
    stack.append(val)
temp = []
while stack:
    element = stack.pop()
    while temp and temp[-1] > element:
        stack.append(temp.pop())
    temp.append(element)
print(temp)
