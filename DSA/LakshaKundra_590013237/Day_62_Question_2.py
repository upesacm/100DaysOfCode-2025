import heapq

def k_closest(arr, target, k):
    heap = []
    for num in arr:
        heapq.heappush(heap, (abs(num - target), num))
    return [heapq.heappop(heap)[1] for _ in range(k)]

print(k_closest([1, 2, 3, 4, 5], 3, 2))
print(k_closest([5, 6, 7, 8, 9], 7, 3))
