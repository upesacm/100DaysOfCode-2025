def sift_down(heap, n, i):
    # Restores heap property by sifting down the element at index i
    largest = i
    left = 2 * i + 1
    right = 2 * i + 2

    # Check if left child exists and is greater than root
    if left < n and heap[left] > heap[largest]:
        largest = left

    # Check if right child exists and is greater than largest so far
    if right < n and heap[right] > heap[largest]:
        largest = right

    # If largest is not root, swap and continue sifting down:
    if largest != i:
        heap[i], heap[largest] = heap[largest], heap[i]
        sift_down(heap, n, largest)

def replace_root(heap, new_element):
    # Replaces root of the heap with new_element and restores heap property.
    n = len(heap)
    if n == 0:
        print("Heap is empty.")
        return

    heap[0] = new_element # Replace root
    sift_down(heap, n, 0) # Restore heap property

try: 
    arr = list(map(int, input("Enter the elements of the array : ").split()))
    newElement = int(input("Enter the new element : "))
    replace_root(arr, newElement)
    print("New heap with root replaced and heap property maintained - ", arr)
except:
    print("Invalid input. Please try with a valid input.")
