def is_max_heap(arr):
    n = len(arr)
    for i in range(n // 2):
        if (2*i+1 < n and arr[i] < arr[2*i+1]) or (2*i+2 < n and arr[i] < arr[2*i+2]):
            return False
    return True

print(is_max_heap([90, 15, 10, 7, 12, 2]))
print(is_max_heap([9, 15, 10, 7, 12, 2]))
