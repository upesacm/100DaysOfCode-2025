def is_heap(arr):
    n = len(arr)
    for i in range((n - 2) // 2 + 1):  # check until last internal node
        left = 2 * i + 1
        right = 2 * i + 2
        if left < n and arr[i] > arr[left]:
            return False
        if right < n and arr[i] > arr[right]:
            return False
    return True

def are_heaps_identical(arr1, arr2):
    if len(arr1) != len(arr2):
        return False
    if arr1 != arr2:
        return False
    return is_heap(arr1) and is_heap(arr2)

# Example usage:
print(are_heaps_identical([10, 9, 8], [10, 9, 8])) 
print(are_heaps_identical([10, 9, 8], [10, 8, 9]))  