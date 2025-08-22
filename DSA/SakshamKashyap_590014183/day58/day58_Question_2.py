def heapify(arr, n, i):
    largest = i
    left = 2 * i + 1   # Left child index
    right = 2 * i + 2  # Right child index

    # If left child exists and is greater than root
    if left < n and arr[left] > arr[largest]:
        largest = left

    # If right child exists and is greater than largest so far
    if right < n and arr[right] > arr[largest]:
        largest = right

    # If largest is not root
    if largest != i:
        arr[i], arr[largest] = arr[largest], arr[i]  # Swap
        heapify(arr, n, largest)  # Recursively heapify the affected sub-tree


def build_max_heap(arr):
    n = len(arr)
    # Start from last non-leaf node and sift down to root
    for i in range(n // 2 - 1, -1, -1):
        heapify(arr, n, i)
    return arr


# Example Usage
arr1 = [3, 5, 9, 6, 8, 20, 10, 12, 18, 9]
print(build_max_heap(arr1))  
# Output: A valid max-heap (e.g., [20, 18, 10, 12, 9, 9, 3, 6, 5, 8])

arr2 = [1, 3, 6, 5, 9, 8]
print(build_max_heap(arr2))  
# Output: [9, 5, 8, 1, 3, 6] or another valid max-heap
