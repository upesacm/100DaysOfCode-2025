def min_heap_to_max_heap(arr):
    n = len(arr)

    # Heapify a subtree rooted at index i for max heap
    def max_heapify(i):
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
            max_heapify(largest)

    # Start from last non-leaf node and heapify each node
    for i in range(n //2 - 1, -1, -1):
        max_heapify(i)

    return arr

try:
    arr = list(map(int, input("Enter the elements of the min heap : ").split()))
    print(min_heap_to_max_heap(arr))
except:
    print("Invalid input. Please try with a valid input.") 
