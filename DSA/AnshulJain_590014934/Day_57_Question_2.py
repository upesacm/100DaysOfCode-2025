arr = list(map(int, input("Enter the array:").split()))
n = len(arr)
is_heap = True
for i in range(n // 2):
    if 2*i + 1 < n and arr[i] < arr[2*i + 1]:
        is_heap = False
        break
    if 2*i + 2 < n and arr[i] < arr[2*i + 2]:
        is_heap = False
        break
print(str(is_heap).lower())
#for example:
#input: arr= 9,15,10,7,12,2
#output: false
