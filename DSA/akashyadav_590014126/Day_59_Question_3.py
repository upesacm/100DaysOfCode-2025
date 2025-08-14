def isHeap(arr):
    n = len(arr)
    for i in range(n // 2):
        left = 2 * i + 1
        right = 2 * i + 2
        if left < n and arr[i] < arr[left]:
            return False
        if right < n and arr[i] < arr[right]:
            return False
    return True

def areHeapsIdentical(arr1, arr2):
    if arr1 != arr2:
        return False
    return isHeap(arr1) and isHeap(arr2)

#example
arr1 = [10, 9, 8]
arr2 = [10, 8, 9]
print(areHeapsIdentical(arr1, arr2))  
