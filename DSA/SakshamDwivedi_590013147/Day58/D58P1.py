import heapq

def kth_smallest(arr, k):
    heapq.heapify(arr)
    for i in range(k - 1):
        heapq.heappop(arr)
    return heapq.heappop(arr)

#Fixed Input
arr = [7, 10, 4, 3, 20, 15]
k = 3
print(kth_smallest(arr, k))
