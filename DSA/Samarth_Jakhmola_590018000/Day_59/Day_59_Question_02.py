import heapq

class MaxHeap:
    def __init__(self):
        self.heap = []   

    # Here we're using the concept that heapq module is a minimum heap by default, so we store negative values internally, so that the
    # smallest negative corresponds to the largest positive.
    def insert(self, value):
        # Push the negative value to simulate max heap
        heapq.heappush(self.heap, -value)

    def extractMax(self):
        if not self.heap:
            return None
        # Pop the smallest negative (which is the largest positive)
        return -heapq.heappop(self.heap)
    
max_heap = MaxHeap()

while True:
    print("\nMenu\n1. Insert\n2. extractMax\n3. Exit")
    
    try:
        choice = int(input("Enter the choice of the operation you want to perform : "))
        if choice == 1:
            element = int(input("Enter the element you want to insert : "))
            max_heap.insert(element)
            
        elif choice == 2:
            result = max_heap.extractMax()
            print("Heap is empty." if result == None else result)

        else:
            break
    except:
        print("Invalid input. Please try with a valid input.")
