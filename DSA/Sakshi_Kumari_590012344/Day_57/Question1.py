import heapq

def k_largest_elements(arr, k):
    if k <= 0 or not arr:
        return []
    heap = arr[:k]
    heapq.heapify(heap)
    for num in arr[k:]:
        if num > heap[0]:
            heapq.heapreplace(heap, num)
    return sorted(heap, reverse=True)
