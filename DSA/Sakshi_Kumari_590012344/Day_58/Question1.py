import heapq

def kth_smallest(arr, k):
    heapq.heapify(arr)
    for _ in range(k - 1):
        heapq.heappop(arr)
    return arr[0]
