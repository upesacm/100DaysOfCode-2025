import heapq
arr = list(map(int, input("Enter The Array:").split()))# taking input for the array
k = int(input("Enter The K: "))# taking input for k
n = len(arr)
prefix = [0] * (n + 1)
for i in range(n):
    prefix[i + 1] = prefix[i] + arr[i]
heap = []
for i in range(n):
    for j in range(i + 1, n + 1):
        s = prefix[j] - prefix[i]
        if len(heap) < k:
            heapq.heappush(heap, s)
        else:
            if s > heap[0]:
                heapq.heappop(heap)
                heapq.heappush(heap, s)

print(heap[0])
# Example:  
# Input: 1 2 3 4 5
# K: 2
# Output: 9