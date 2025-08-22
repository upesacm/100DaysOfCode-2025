import heapq

def kth_smallest(arr, k):
    heapq.heapify(arr)
    for _ in range(k-1):
        heapq.heappop(arr)
    return heapq.heappop(arr)

print(kth_smallest([7, 10, 4, 3, 20, 15], 3))
print(kth_smallest([7, 10, 4, 20, 15], 4))
