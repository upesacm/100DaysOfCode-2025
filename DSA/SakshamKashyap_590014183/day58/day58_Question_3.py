def heapify(arr, n, i):
    largest = i
    left = 2 * i + 1
    right = 2 * i + 2

    # Check if left child exists and is greater
    if left < n and arr[left] > arr[largest]:
        largest = left

    # Check if right child exists and is greater
    if right < n and arr[right] > arr[largest]:
        largest = right

    # If largest is not root
    if largest != i:
        arr[i], arr[largest] = arr[largest], arr[i]
        heapify(arr, n, largest)

def replace_root(arr, newElement):
    # Replace root with new value
    arr[0] = newElement
    # Restore heap property
    heapify(arr, len(arr), 0)
    return arr

# Example Usage
heap1 = [50, 30, 20, 15, 10, 8, 16]
print(replace_root(heap1, 25))
# Output: [30, 25, 20, 15, 10, 8, 16] (valid max-heap)

heap2 = [100, 80, 70, 60, 50, 40, 30]
print(replace_root(heap2, 35))
# Output: [80, 60, 70, 35, 50, 40, 30] (valid max-heap)
