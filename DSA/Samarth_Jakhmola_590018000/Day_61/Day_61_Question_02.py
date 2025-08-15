# Function to heapify (sift-down) a node in a max heap
def heapify_down(heap, index):
    size = len(heap)
    largest = index
    left = 2 * index + 1
    right = 2 * index + 2

    # Check if left child exists and is greater than current largest
    if left < size and heap[left] > heap[largest]:
        largest = left

    # Check if right child exists and is greater than current largest
    if right < size and heap[right] > heap[largest]:
        largest = right

    # If largest is not the current node, swap and continue heapifying
    if largest != index:
        heap[index], heap[largest] = heap[largest], heap[index]
        heapify_down(heap, largest)

# Function to heapify upwards (bubble-up) after insertion
def heapify_up(heap, index):
    parent = (index - 1) // 2
    # Continue until we reach the root or heap property is satisfied
    while index > 0 and heap[index] > heap[parent]:
        heap[index], heap[parent] = heap[parent], heap[index]
        index = parent
        parent = (index - 1) // 2

# Function to insert a new value into max heap
def insert(heap, value):
    heap.append(value)   # Add new value at the end
    heapify_up(heap, len(heap) - 1)  # Restore heap property

# Function to delete root (max element) from max heap
def delete_root(heap):
    if len(heap) == 0:
        return None  # Empty heap
    root_value = heap[0]
    heap[0] = heap[-1] # Move last element to root
    heap.pop()         # Remove last element
    if heap:
        heapify_down(heap, 0)  # Restore heap property
    return root_value

try:
    heap = []
    while True:
        print("\nMenu\n 1. Insertion \n 2. Delete root \n 3. Exit \n")
        choice = int(input("Enter the choice corresponding to the operation you want to perform : "))
        if choice == 1:
            element = int(input("Enter the element you want to insert : "))
            insert(heap, element)
            print(f"After insertion : {heap}")
        if choice == 2:
            delete_root(heap)
            print(f"After deletion : {heap}")
        if choice == 3:
            print("You've exited the program.")
            break
except:
    print("Invalid input. Please try with a valid input.")
