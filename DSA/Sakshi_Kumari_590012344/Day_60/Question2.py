import heapq

class MedianFinder:
    def __init__(self):
        self.max_heap = []  
        self.min_heap = []  

    def add_num(self, num):
        heapq.heappush(self.max_heap, -num)
        
        if (self.max_heap and self.min_heap and 
            (-self.max_heap[0] > self.min_heap[0])):
            value = -heapq.heappop(self.max_heap)
            heapq.heappush(self.min_heap, value)

        if len(self.max_heap) > len(self.min_heap) + 1:
            value = -heapq.heappop(self.max_heap)
            heapq.heappush(self.min_heap, value)

        if len(self.min_heap) > len(self.max_heap):
            value = heapq.heappop(self.min_heap)
            heapq.heappush(self.max_heap, -value)

    def find_median(self):
        if len(self.max_heap) > len(self.min_heap):
            return -self.max_heap[0]
        return (-self.max_heap[0] + self.min_heap[0]) / 2
