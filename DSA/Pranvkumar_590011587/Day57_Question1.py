import heapq

def k_largest_elements(arr, k):
    if k <= 0 or k > len(arr):
        return []
    min_heap = arr[:k]
    heapq.heapify(min_heap)
    for num in arr[k:]:
        if num > min_heap[0]:
            heapq.heappushpop(min_heap, num)
    return sorted(min_heap, reverse=True)

# Examples
print(k_largest_elements([1, 23, 12, 9, 30, 2, 50], 3)) # [50, 30, 23]
print(k_largest_elements([10, 15, 5], 2))               # [15, 10]
