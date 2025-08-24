#Implement distance-based k-closest selection using heap structures with custom distance comparators for optimal proximity analysis.
import heapq
def k_closest(arr, k, target):
    heap = []
    for num in arr:
        heapq.heappush(heap, (-abs(num - target), num))
        if len(heap) > k:
            heapq.heappop(heap)
    return sorted([num for _, num in heap])

arr = list(map(int, input("Enter array: ").split()))
k = int(input("Enter k: "))
target = int(input("Enter target: "))
print(k_closest(arr, k, target))
