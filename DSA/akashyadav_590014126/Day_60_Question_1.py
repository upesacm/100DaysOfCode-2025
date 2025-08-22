import heapq
def sort_k_sorted_array(arr,k):
    n=len(arr)
    min_heap=arr[:k+1]
    heapq.heapify(min_heap)

    target_index=0
    for i in range(k+1,n):
        arr[target_index]=heapq.heappop(min_heap)
        heapq.heappush(min_heap,arr[i])
        target_index += 1
    
    while min_heap:
        arr[target_index]=heapq.heappop(min_heap)
        target_index += 1

    return arr