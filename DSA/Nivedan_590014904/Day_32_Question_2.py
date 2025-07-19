arr = []
n = int(input("Enter the number of elements in array:- "))
for i in range(n):
    val = int(input(f"Enter the {i} element: "))
    arr.append(val)
for i in range(len(arr)):
    for j in range(len(arr)):
        if arr[i]^arr[j]==0 and i!=j:
            break
    else:
        print(arr[i])
