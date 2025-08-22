import heapq

class MedianFinder:
    def __init__(self):
        self.small = []  # max-heap (store as negative values)
        self.large = []  # min-heap

    def add_num(self, num):
        # Step 1: Push to max-heap (small) first
        heapq.heappush(self.small, -num)

        heapq.heappush(self.large, -heapq.heappop(self.small))

        if len(self.large) > len(self.small):
            heapq.heappush(self.small, -heapq.heappop(self.large))

    def find_median(self):
        if len(self.small) > len(self.large):
            return -self.small[0]
        else:
            return (-self.small[0] + self.large[0]) / 2

mf = MedianFinder()
stream = [5, 15, 1, 3]
for num in stream:
    mf.add_num(num)
    print(mf.find_median())

mf2 = MedianFinder()
stream2 = [1, 2, 3, 4, 5]
for num in stream2:
    mf2.add_num(num)
    print(mf2.find_median())
