import heapq

class MaxHeap:
    def __init__(self):
        self.heap = []

    def insert(self, val):
        # Push negative for max-heap behavior
        heapq.heappush(self.heap, -val)

    def extractMax(self):
        if not self.heap:
            return None
        return -heapq.heappop(self.heap)

# Example usage:
mh = MaxHeap()
mh.insert(5)
mh.insert(1)
mh.insert(10)
print(mh.extractMax())  # Output: 10
