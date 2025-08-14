import heapq

def kth_smallest_min_heap(arr, k):
    """
    Returns the kth smallest element in the array using a min-heap.
    :param arr: List[int] - input array
    :param k: int - kth position (1-based)
    :return: int - kth smallest element
    """
    if not arr or k < 1 or k > len(arr):
        raise ValueError("Invalid input: k out of range or array is empty.")
    
    # Create a min-heap from the array
    heap = arr[:]
    heapq.heapify(heap)
    
    # Extract min k-1 times
    for _ in range(k-1):
        heapq.heappop(heap)
    
    return heapq.heappop(heap)

# Example usage
if __name__ == "__main__":
    arr1 = [7, 10, 4, 3, 20, 15]
    k1 = 3
    print(kth_smallest_min_heap(arr1, k1))  # Output: 7

    arr2 = [7, 10, 4, 20, 15]
    k2 = 4
    print(kth_smallest_min_heap(arr2, k2))  # Output: 15
