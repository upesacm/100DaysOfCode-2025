import heapq
arr = list(map(int, input(" Enter The Array:").split()))#   taking input for the array
target = int(input("Enter The Target: "))#  taking input for target
k = int(input("Enter The K: ")) #  taking input for k
heap = []
for num in arr:
    dist = abs(num - target)
    heapq.heappush(heap, (-dist, -num))
    if len(heap) > k:
        heapq.heappop(heap)
result = sorted([-num for _, num in heap])
print(result)
# Example:
# Input: 1 2 3 4 5
# Target: 3
# K: 2
# Output: [2, 4]