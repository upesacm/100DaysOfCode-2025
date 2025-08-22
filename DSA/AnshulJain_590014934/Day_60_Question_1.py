import heapq
arr = list(map(int, input("Enter the array:").split()))
k = int(input("Enter the value of k:"))
heap = arr[:k+1]
heapq.heapify(heap)
target_index = 0
for i in range(k+1, len(arr)):
    arr[target_index] = heapq.heappop(heap)
    target_index += 1
    heapq.heappush(heap, arr[i])
while heap:
    arr[target_index] = heapq.heappop(heap)
    target_index += 1
print(arr)
#for exapmle:
# input:-6 5 3 2 8 10 9
# k: 3
# output :-[2, 3, 5, 6, 8, 9, 10]