import heapq

def sort_k_sorted_array(arr, k):
    heap = arr[:k+1]
    heapq.heapify(heap)
    target_index = 0
    
    for i in range(k+1, len(arr)):
        arr[target_index] = heapq.heappop(heap)
        heapq.heappush(heap, arr[i])
        target_index += 1

    while heap:
        arr[target_index] = heapq.heappop(heap)
        target_index += 1

    return arr


# Example usage
print(sort_k_sorted_array([6, 5, 3, 2, 8, 10, 9], 3))  
# Output: [2, 3, 5, 6, 8, 9, 10]
print(sort_k_sorted_array([3, 2, 1, 5, 4, 7, 6, 5], 3))  
# Output: [1, 2, 3, 4, 5, 5, 6, 7]
