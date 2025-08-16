import heapq

def k_closest_numbers(arr, target, k):
    max_heap = []
    
    for num in arr:
        distance = abs(num - target)
        # Push (-distance, -num) so heap pops farthest, and smaller values first if tie
        heapq.heappush(max_heap, (-distance, -num))
        
        if len(max_heap) > k:
            heapq.heappop(max_heap)
    
    # Extract numbers, negate back
    result = [-num for _, num in max_heap]
    return sorted(result)

# Examples
print(k_closest_numbers([1, 2, 3, 4, 5], 3, 2))  # [2, 4]
print(k_closest_numbers([5, 6, 7, 8, 9], 7, 3))  # [6, 7, 8]
