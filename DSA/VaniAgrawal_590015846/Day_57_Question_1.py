import heapq

# K Largest Elements using Min-Heap
arr = list(map(int, input("Enter array elements separated by space: ").split()))
k = int(input("Enter value of k: "))

# Min-heap for k largest elements
min_heap = arr[:k]
heapq.heapify(min_heap)

for num in arr[k:]:
    if num > min_heap[0]:
        heapq.heappop(min_heap)
        heapq.heappush(min_heap, num)

# Output sorted in descending order
result = sorted(min_heap, reverse=True)
print("K largest elements:", result)
