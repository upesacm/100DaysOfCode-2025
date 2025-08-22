import heapq

def kth_smallest_minheap(arr, k):
    heapq.heapify(arr)  
    for _ in range(k - 1):
        heapq.heappop(arr)  
    return heapq.heappop(arr)

# Example usage:
print(kth_smallest_minheap([7, 10, 4, 3, 20, 15], 3)) 
print(kth_smallest_minheap([7, 10, 4, 20, 15], 4))     