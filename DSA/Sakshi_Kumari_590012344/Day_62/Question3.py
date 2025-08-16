import heapq

def kth_largest_subarray_sum(arr, k):
    n = len(arr)
    prefix = [0] * (n + 1)
    for i in range(n):
        prefix[i+1] = prefix[i] + arr[i]

    heap = []
    for i in range(n):
        for j in range(i+1, n+1):
            sub_sum = prefix[j] - prefix[i]
            heapq.heappush(heap, sub_sum)
            if len(heap) > k:
                heapq.heappop(heap)
    return heap[0]
