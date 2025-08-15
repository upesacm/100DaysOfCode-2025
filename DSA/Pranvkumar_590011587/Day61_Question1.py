def heapify_max(arr, n, i):
    largest = i
    left = 2 * i + 1
    right = 2 * i + 2

    if left < n and arr[left] > arr[largest]:
        largest = left
    if right < n and arr[right] > arr[largest]:
        largest = right

    if largest != i:
        arr[i], arr[largest] = arr[largest], arr[i]
        heapify_max(arr, n, largest)


def min_to_max_heap(arr):
    n = len(arr)
    for i in range(n//2 - 1, -1, -1):
        heapify_max(arr, n, i)
    return arr

# Example
arr1 = [1, 3, 5, 7, 9, 2]
print("Converted Max Heap:", min_to_max_heap(arr1))
arr2 = [2, 4, 6, 8, 10, 12]
print("Converted Max Heap:", min_to_max_heap(arr2))