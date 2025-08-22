import heapq

def sort_k_sorted_array(arr, k):
    n = len(arr)
    heap = []
    for i in range(min(k+1, n)):
        heapq.heappush(heap, arr[i])
    index = 0  
    for i in range(k+1, n):
        arr[index] = heapq.heappop(heap)
        index += 1
        heapq.heappush(heap, arr[i])
    while heap:
        arr[index] = heapq.heappop(heap)
        index += 1
    return arr

# Example
print(sort_k_sorted_array([6, 5, 3, 2, 8, 10, 9], 3))
print(sort_k_sorted_array([3, 2, 1, 5, 4, 7, 6, 5], 3))