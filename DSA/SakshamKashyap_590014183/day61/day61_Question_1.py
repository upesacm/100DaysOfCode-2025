def minHeapToMaxHeap(arr):
    n = len(arr)

    def maxHeapify(i, n):
        left = 2 * i + 1
        right = 2 * i + 2
        largest = i

        if left < n and arr[left] > arr[largest]:
            largest = left
        if right < n and arr[right] > arr[largest]:
            largest = right

        if largest != i:
            arr[i], arr[largest] = arr[largest], arr[i]
            maxHeapify(largest, n)

    # Start from last non-leaf node
    for i in range(n // 2 - 1, -1, -1):
        maxHeapify(i, n)

# Example 1
arr1 = [1, 3, 5, 7, 9, 2]
minHeapToMaxHeap(arr1)
print("Converted to Max Heap:", arr1)

# Example 2
arr2 = [2, 4, 6, 8, 10, 12]
minHeapToMaxHeap(arr2)
print("Converted to Max Heap:", arr2)
