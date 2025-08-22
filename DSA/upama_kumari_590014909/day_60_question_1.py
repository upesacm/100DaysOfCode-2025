import heapq

def sort_k_sorted_array(arr, k):
    heap = []
    result = []

    for i in range(min(k + 1, len(arr))):
        heapq.heappush(heap, arr[i])

    for i in range(k + 1, len(arr)):
        result.append(heapq.heappop(heap))
        heapq.heappush(heap, arr[i])

    while heap:
        result.append(heapq.heappop(heap))

    return result

print(sort_k_sorted_array([6, 5, 3, 2, 8, 10, 9], 3))
print(sort_k_sorted_array([3, 2, 1, 5, 4, 7, 6, 5], 3))
