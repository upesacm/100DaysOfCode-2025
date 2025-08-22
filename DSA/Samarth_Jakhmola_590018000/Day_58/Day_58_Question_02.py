def heapify(arr, n, i):
    largest = i
    left = 2 * i + 1
    right = 2 * i + 2

    # Check if left child exists and is greater than root
    if left < n and arr[left] > arr[largest]:
        largest = left

    # Check if right child exists and is greater than largest so far
    if right < n and arr[right] > arr[largest]:
        largest = right

    # If largest != i:
        arr[i], arr[largest] = arr[largest], arr[i]
        heapify(arr, n, largest)

def build_max_heap(arr):
    n = len(arr)

    # Start from last non - leaf node and move upward
    for i in range(n // 2 - 1, -1, -1):
        heapify(arr, n, i)

try: 
    arr = list(map(int, input("Enter the elements of the array : ").split()))
    build_max_heap(arr)
    print("A valid max-heap array - ", arr)
except:
    print("Invalid input. Please try with a valid input.")
