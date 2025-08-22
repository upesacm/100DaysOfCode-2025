import heapq
from collections import Counter

def top_k_frequent(nums, k):
    freq = Counter(nums)
    heap = []

    for num, count in freq.items():
        heapq.heappush(heap, (count, num))
        if len(heap) > k:
            heapq.heappop(heap)

    return [num for count, num in heap]

print(top_k_frequent([1, 1, 1, 2, 2, 3], 2))
print(top_k_frequent([4, 1, -1, 2, -1, 2, 3], 2))
