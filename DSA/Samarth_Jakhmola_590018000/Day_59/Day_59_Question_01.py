class MinHeap:
    def __init__(self):
        self.heap = []

    def insert(self, key):
        self.heap.append(key)  # Adds an eleemnt at the end.
        self.bubble_up(len(self.heap) - 1)  # Adjusts the new element to its correct position in the heap.

    def extractMin(self):
        if not self.heap:   # Checking if the heap is empty and returning None if it is.
            return None
        if len(self.heap) == 1:
            return self.heap.pop()    # If there's only one element present, returns it.
        
        root = self.heap[0]  # Storing the minimum element.
        self.heap[0] = self.heap.pop()  # Moves the last element to the root.
        self.bubble_down(0)
        return root
    
    def bubble_up(self, index):
        parent = (index - 1)  // 2
        while index > 0 and self.heap[index] < self.heap[parent]:
            self.heap[index], self.heap[parent] = self.heap[parent], self.heap[index]
            index = parent
            parent = (index - 1) // 2

    def bubble_down(self, index):
        smallest = index
        left = 2 * index + 1
        right = 2 * index + 2

        if left < len(self.heap) and self.heap[left] < self.heap[smallest]:
            smallest = left
        if right < len(self.heap) and self.heap[right] < self.heap[smallest]:
            smallest = right

        if smallest != index:
            self.heap[index], self.heap[smallest] = self.heap[smallest], self.heap[index]
            self.bubble_down(smallest)

min_heap = MinHeap()

while True:
    print("\nMenu\n1. Insert\n2. extractMin\n3. Exit")
    
    try:
        choice = int(input("Enter the choice of the operation you want to perform : "))
        if choice == 1:
            element = int(input("Enter the element you want to insert : "))
            min_heap.insert(element)
            
        elif choice == 2:
            result = min_heap.extractMin()
            print("Heap is empty" if result == None else result)

        else:
            break
    except:
        print("Invalid input. Please try with a valid input.")
