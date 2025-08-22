import heapq

def k_largest_elements(arr, k):
    if k <= 0:
        return []
    min_heap = []
    for num in arr:
        heapq.heappush(min_heap, num)
        if len(min_heap) > k:
            heapq.heappop(min_heap)
    return sorted(min_heap, reverse=True)

print(k_largest_elements([1, 23, 12, 9, 30, 2, 50], 3))  
print(k_largest_elements([10, 15, 5], 2))               
