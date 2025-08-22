import heapq

def k_largest_elements(arr, k):
    if k <= 0:
        return []
    if k >= len(arr):
        return sorted(arr, reverse=True)

    # Step 1: Create a min-heap with first k elements
    min_heap = arr[:k]
    heapq.heapify(min_heap)  # O(k)

    # Step 2: Iterate over remaining elements
    for num in arr[k:]:
        if num > min_heap[0]:  # If larger than heap's smallest
            heapq.heapreplace(min_heap, num)  # O(log k)

    # Step 3: Sort in descending order for output
    return sorted(min_heap, reverse=True)

# Example usage
print(k_largest_elements([1, 23, 12, 9, 30, 2, 50], 3))  # [50, 30, 23]
print(k_largest_elements([10, 15, 5], 2))               # [15, 10]
