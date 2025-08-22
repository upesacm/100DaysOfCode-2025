import heapq

def kth_largest_subarray_sum(arr, k):
    n = len(arr)
    min_heap = []
    
    # Generate all subarray sums
    for start in range(n):
        curr_sum = 0
        for end in range(start, n):
            curr_sum += arr[end]
            
            heapq.heappush(min_heap, curr_sum)
            
            # keep only k largest in heap
            if len(min_heap) > k:
                heapq.heappop(min_heap)
    
    return min_heap[0]

# Examples
print(kth_largest_subarray_sum([10, -10, 20, -40], 3))  # 10
print(kth_largest_subarray_sum([1, 2, 3], 2))  # 5
