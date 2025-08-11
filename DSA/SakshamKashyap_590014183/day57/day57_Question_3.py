import heapq

def merge_k_sorted_arrays(arrays):
    heap = []  # Min-heap
    result = []

    # Step 1: Push the first element of each array into the heap
    for i, arr in enumerate(arrays):
        if arr:  # Avoid empty arrays
            heapq.heappush(heap, (arr[0], i, 0))  # (value, array_index, element_index)

    # Step 2: Extract the smallest, then push the next element from the same array
    while heap:
        val, arr_idx, ele_idx = heapq.heappop(heap)
        result.append(val)

        next_idx = ele_idx + 1
        if next_idx < len(arrays[arr_idx]):
            heapq.heappush(heap, (arrays[arr_idx][next_idx], arr_idx, next_idx))

    return result

# Example usage
print(merge_k_sorted_arrays([[1, 3], [2, 4], [5, 6]]))  
# Output: [1, 2, 3, 4, 5, 6]

print(merge_k_sorted_arrays([[1, 4, 5], [1, 3, 4], [2, 6]]))  
# Output: [1, 1, 2, 3, 4, 4, 5, 6]
