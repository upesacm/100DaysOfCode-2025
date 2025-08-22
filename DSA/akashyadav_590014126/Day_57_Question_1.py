import heapq

def k_largest_elements(arr, k):
    if k<=0 or not arr:
        return []
    
    min_heap=arr[:k]
    heapq.heapify(min_heap)

    for num in arr[k:]:
        if num >min_heap[0]:
            heapq.heappushpop(min_heap, num)
    
    return sorted(min_heap,reverse=True)

#example
arr1 = [9, 54, 22, 99, 30, 1, 20]
k1 = 5
print(k_largest_elements(arr1, k1))