stack = []
minimum = []
n = int(input("ENter the number of elements to be put in the stack: "))
for i in range(n):
    val = int(input(f"Input the {i+1} element: "))
    stack.append(val)
    if not minimum  or val <= minimum[-1]:
        minimum.append(val)
print("Min:",minimum[-1])
