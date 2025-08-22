def heapify_down(arr, n, i):
    largest = i
    left = 2 * i + 1
    right = 2 * i + 2

    if left < n and arr[left] > arr[largest]:
        largest = left
    if right < n and arr[right] > arr[largest]:
        largest = right

    if largest != i:
        arr[i], arr[largest] = arr[largest], arr[i]
        heapify_down(arr, n, largest)

arr = list(map(int, input("Enter heap elements separated by space: ").split()))
newElement = int(input("Enter new element to replace root: "))

arr[0] = newElement

heapify_down(arr, len(arr), 0)

print("New heap with root replaced and heap property maintained:")
print(arr)
