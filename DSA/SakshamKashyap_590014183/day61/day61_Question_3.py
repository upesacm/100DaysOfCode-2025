def heapSort(arr):
    n = len(arr)

    def heapify(i, heap_size):
        largest = i
        left = 2 * i + 1
        right = 2 * i + 2

        if left < heap_size and arr[left] > arr[largest]:
            largest = left
        if right < heap_size and arr[right] > arr[largest]:
            largest = right

        if largest != i:
            arr[i], arr[largest] = arr[largest], arr[i]
            heapify(largest, heap_size)

    # Build Max Heap
    for i in range(n // 2 - 1, -1, -1):
        heapify(i, n)

    # Extract elements
    for i in range(n - 1, 0, -1):
        arr, arr[i] = arr[i], arr
        heapify(0, i)

# Example 1
data1 = [4, 10, 3, 5, 1]
heapSort(data1)
print("Sorted array:", data1)

# Example 2
data2 = [12, 11, 13, 5, 6, 7]
heapSort(data2)
print("Sorted array:", data2)
