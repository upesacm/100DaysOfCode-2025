def heap_sort(arr):
    n = len(arr)
    for i in range(n // 2 - 1, -1, -1):
        sift_down(arr, n, i)
    for i in range(n - 1, 0, -1):
        arr[0], arr[i] = arr[i], arr[0]
        sift_down(arr, i, 0)

def sift_down(arr, size, index):
    largest = index
    left = 2 * index + 1
    right = 2 * index + 2
    if left < size and arr[left] > arr[largest]:
        largest = left
    if right < size and arr[right] > arr[largest]:
        largest = right
    if largest != index:
        arr[index], arr[largest] = arr[largest], arr[index]
        sift_down(arr, size, largest)
