stack = []
cons = []
n = int(input("ENter the number of elements to be put in the stack: "))
for i in range(n):
    val = int(input(f"Input for  the {i+1} day: "))
    stack.append(val)
for i in range(n):
    count = 1
    j = i-1
    while j>=0 and stack[i] >= stack[j]:
        count+=1
        j-=1
    cons.append(count)
print(cons)
