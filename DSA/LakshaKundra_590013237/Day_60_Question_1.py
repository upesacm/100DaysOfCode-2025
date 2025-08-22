import heapq

def sort_k_sorted(arr, k):
    heap = arr[:k+1]
    heapq.heapify(heap)
    target_index = 0
    for remaining in arr[k+1:]:
        arr[target_index] = heapq.heappop(heap)
        heapq.heappush(heap, remaining)
        target_index += 1
    while heap:
        arr[target_index] = heapq.heappop(heap)
        target_index += 1
    return arr

print(sort_k_sorted([6, 5, 3, 2, 8, 10, 9], 3))
print(sort_k_sorted([3, 2, 1, 5, 4, 7, 6, 5], 3))
