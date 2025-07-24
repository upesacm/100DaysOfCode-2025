n = int(input("Enter number of elements: "))
arr = []

for i in range(n):
    val = int(input(f"Enter element {i+1}: "))
    arr.append(val)
newarr = []
for i in range(n):
    greatest = -1
    for j in range(i+1,n):
        if arr[i]<arr[j]:
            greatest= arr[j]
            break
    newarr.append(greatest)
print(newarr)
