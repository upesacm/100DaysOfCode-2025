import heapq

def merge_k_sorted_arrays(arrays):
    min_heap = []
    result = []
    
    for i, arr in enumerate(arrays):
        if arr:  
            heapq.heappush(min_heap, (arr[0], i, 0))
    
    while min_heap:
        val, arr_idx, ele_idx = heapq.heappop(min_heap)
        result.append(val)
        
        if ele_idx + 1 < len(arrays[arr_idx]):
            heapq.heappush(min_heap, (arrays[arr_idx][ele_idx + 1], arr_idx, ele_idx + 1))
    
    return result

print(merge_k_sorted_arrays([[1, 3], [2, 4], [5, 6]]))
print(merge_k_sorted_arrays([[1, 4, 5], [1, 3, 4], [2, 6]])) 
