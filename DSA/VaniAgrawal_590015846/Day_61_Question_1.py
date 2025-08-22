# Implement bottom-up max-heapification on existing min-heap structure to efficiently convert heap properties while preserving all elements.
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

arr = list(map(int, input("Enter min heap elements (space-separated): ").split()))
n = len(arr)

for i in range(n // 2 - 1, -1, -1):
    heapify_max(arr, n, i)

print("Max heap:", arr)
