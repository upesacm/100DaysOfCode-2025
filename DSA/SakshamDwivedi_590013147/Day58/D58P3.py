def heapify(arr, n, i):
    largest = i
    left = 2 * i + 1
    right = 2 * i + 2
    if left < n and arr[left] > arr[largest]:
        largest = left
    if right < n and arr[right] > arr[largest]:
        largest = right
    if largest != i:
        arr[i], arr[largest] = arr[largest], arr[i]
        heapify(arr, n, largest)


def replace_root(arr, newElement):
    if not arr:
        return
    arr[0] = newElement
    heapify(arr, len(arr), 0)


#Fixed Input
arr = [50, 30, 20, 15, 10, 8, 16]
newElement = 25
replace_root(arr, newElement)
print("Updated Heap:", arr)
