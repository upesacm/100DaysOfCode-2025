import heapq

def k_closest_numbers(arr, k, target):
    heap = []
    for num in arr:
        dist = abs(num - target)
        heapq.heappush(heap, (-dist, num))
        if len(heap) > k:
            heapq.heappop(heap)
    return [num for _, num in heap]
