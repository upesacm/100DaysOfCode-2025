#Implement subarray sum analysis using heap-based selection to efficiently identify kth largest segment sums with optimal performance.
import heapq
def kth_largest_sum(arr, k):
    n = len(arr)
    prefix = [0] * (n + 1)
    for i in range(n):
        prefix[i+1] = prefix[i] + arr[i]
    heap = []
    for i in range(n):
        for j in range(i+1, n+1):
            s = prefix[j] - prefix[i]
            if len(heap) < k:
                heapq.heappush(heap, s)
            else:
                if s > heap[0]:
                    heapq.heapreplace(heap, s)
    return heap[0]

arr = list(map(int, input("Enter array: ").split()))
k = int(input("Enter k: "))
print(kth_largest_sum(arr, k))
