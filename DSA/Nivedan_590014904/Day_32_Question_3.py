arr = []
n = int(input("Enter the number of elements in array:- "))
for i in range(n):
    val = int(input(f"Enter the {i} element: "))
    arr.append(val)
xor =  arr[0]
for i in range(1,len(arr)):
    xor = xor^arr[i]
print(xor)
