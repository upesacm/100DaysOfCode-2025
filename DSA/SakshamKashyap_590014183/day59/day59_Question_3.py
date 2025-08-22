def is_heap(arr):
    n = len(arr)
    for i in range((n // 2)):
        left = 2 * i + 1
        right = 2 * i + 2
        if left < n and arr[i] > arr[left]:
            return False
        if right < n and arr[i] > arr[right]:
            return False
    return True

def are_identical_heaps(arr1, arr2):
    return arr1 == arr2 and is_heap(arr1) and is_heap(arr2)


# Example usage
print(are_identical_heaps([10, 9, 8], [10, 9, 8]))  # True
print(are_identical_heaps([10, 9, 8], [10, 8, 9]))  # False
