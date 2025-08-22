import heapq

class MaxHeap:
    def __init__(self):
        self.heap = []

    def insert(self, val):
        heapq.heappush(self.heap, -val)

    def extractMax(self):
        if not self.heap:
            return None
        return -heapq.heappop(self.heap)
