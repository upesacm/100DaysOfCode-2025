def is_heap(arr):
    n = len(arr)
    for i in range(n // 2):
        left = 2 * i + 1
        right = 2 * i + 2
        if left < n and arr[i] > arr[left]:
            return False
        if right < n and arr[i] > arr[right]:
            return False
    return True
arr1 = list(map(int, input("Enter the array 1:").strip().split()))
arr2 = list(map(int, input("Enter The array 2:").strip().split()))
if arr1 == arr2 :
    print("true")
else:
    print("false")
#for example:
#input:arr_1:- 10 8 9
#       arr_2:- 10 9 8
#output: false 