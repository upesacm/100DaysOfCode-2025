import heapq
arr = list(map(int, input("Enter the array:").split()))
k = int(input("Enter the value of k:"))
heapq.heapify(arr)
for _ in range(k - 1):
    heapq.heappop(arr)
print(heapq.heappop(arr))
#for example:
# Input: 7 10 4 3 20 15
# Input: 3
# Output: 10