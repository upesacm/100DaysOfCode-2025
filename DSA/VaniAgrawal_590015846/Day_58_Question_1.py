import heapq

arr = list(map(int, input("Enter array elements separated by space: ").split()))
k = int(input("Enter value of k: "))

min_heap = arr[:]
heapq.heapify(min_heap)

kth_smallest = None
for _ in range(k):
    kth_smallest = heapq.heappop(min_heap)

print(f"{k}th smallest element:", kth_smallest)
