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

def replace_root_maxheap(arr, newElement):
    n = len(arr)
    arr[0] = newElement 
    heapify_max(arr, n, 0) 
    return arr

# Example usage:
print(replace_root_maxheap([50, 30, 20, 15, 10, 8, 16], 25))
print(replace_root_maxheap([100, 80, 70, 60, 50, 40, 30], 35))