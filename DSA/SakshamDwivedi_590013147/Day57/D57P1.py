import heapq

def k_largest_el(arr, k):
    heap = arr[:k]
    heapq.heapify(heap)
    
    for num in arr[k:]:
        if num > heap[0]:
            heapq.heapreplace(heap, num)
    
    return sorted(heap, reverse=True)

#Fixed Input
arr = [1, 23, 12, 9, 30, 2, 50]
k = 3
print(k_largest_el(arr, k))
