import heapq

class MedianFinder:
    def __init__(self):
        self.max_heap = []  
        self.min_heap = []  

    def add_num(self, num):
        heapq.heappush(self.max_heap, -num)
        if self.max_heap and self.min_heap and (-self.max_heap[0] > self.min_heap[0]):
            val = -heapq.heappop(self.max_heap)
            heapq.heappush(self.min_heap, val)
        if len(self.max_heap) > len(self.min_heap) + 1:
            heapq.heappush(self.min_heap, -heapq.heappop(self.max_heap))
        elif len(self.min_heap) > len(self.max_heap) + 1:
            heapq.heappush(self.max_heap, -heapq.heappop(self.min_heap))
    def find_median(self):
        if len(self.max_heap) == len(self.min_heap):
            return (-self.max_heap[0] + self.min_heap[0]) / 2
        elif len(self.max_heap) > len(self.min_heap):
            return -self.max_heap[0]
        else:
            return self.min_heap[0]

# Example
mf = MedianFinder()
stream = [5, 15, 1, 3]
for num in stream:
    mf.add_num(num)
    print(mf.find_median())