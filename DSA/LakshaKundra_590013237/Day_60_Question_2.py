import heapq

def median_stream(nums):
    min_heap, max_heap = [], []
    res = []
    for num in nums:
        if not max_heap or num <= -max_heap[0]:
            heapq.heappush(max_heap, -num)
        else:
            heapq.heappush(min_heap, num)
        if len(max_heap) > len(min_heap) + 1:
            heapq.heappush(min_heap, -heapq.heappop(max_heap))
        elif len(min_heap) > len(max_heap):
            heapq.heappush(max_heap, -heapq.heappop(min_heap))
        if len(max_heap) == len(min_heap):
            res.append((-max_heap[0] + min_heap[0]) / 2)
        else:
            res.append(-max_heap[0])
    return res

print(median_stream([5, 15, 1, 3]))
print(median_stream([1, 2, 3, 4, 5]))
