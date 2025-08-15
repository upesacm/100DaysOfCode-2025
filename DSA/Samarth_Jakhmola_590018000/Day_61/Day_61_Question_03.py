def heapify(arr, n, i):
    largest = i
    left = 2 * i + 1
    right = 2 * i + 2

    # Check if left child exists and is greater than root
    if left < n and arr[left] > arr[largest]:
            largest = left

    # Check if right child exists and is greater than current largest
    if right < n and arr[right] > arr[largest]:
            largest = right

    # If largest is not root, swap and heapify the affected subtree
    if largest != i:
        arr[i], arr[largest] = arr[largest], arr[i]
        heapify(arr, n, largest)

def heap_sort(arr):
    n = len(arr)

    # Build max heap
    for i in range(n//2 - 1, -1, -1):
        heapify(arr, n, i)

    # Extract elements
    for i in range(n-1, 0, -1):
        arr[i], arr[0] = arr[0], arr[i]
        heapify(arr, i, 0)

try:
    arr = list(map(int, input("Enter the elements of the array : ").split()))
    heap_sort(arr)
    print(arr)
except:
     print("Invalid input. Please enter a valid input.")
