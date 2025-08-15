import heapq

class MedianFinder:
    def __init__(self):
        self.small = []  # max-heap (invert values)
        self.large = []  # min-heap

    def add_num(self, num):
        # Push to max heap (small)
        heapq.heappush(self.small, -num)

        # Ensure every element in small <= every element in large
        if self.small and self.large and (-self.small[0] > self.large[0]):
            heapq.heappush(self.large, -heapq.heappop(self.small))

        # Balance sizes
        if len(self.small) > len(self.large) + 1:
            heapq.heappush(self.large, -heapq.heappop(self.small))
        elif len(self.large) > len(self.small):
            heapq.heappush(self.small, -heapq.heappop(self.large))

    def find_median(self):
        if len(self.small) > len(self.large):
            return -self.small[0]
        return (-self.small[0] + self.large[0]) / 2


# Example usage
mf = MedianFinder()
for num in [5, 15, 1, 3]:
    mf.add_num(num)
    print(mf.find_median(), end=", ")  
# Output: 5, 10, 5, 4
