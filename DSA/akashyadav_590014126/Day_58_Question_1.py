import heapq
def kth_smallest_min_heap(arr,k):
    heapq.heapify(arr)
    for _ in range(k-1):
        heapq.heappop(arr)
    return heapq.heappop(arr)