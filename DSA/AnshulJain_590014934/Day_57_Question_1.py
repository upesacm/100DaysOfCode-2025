import heapq
arr = list(map(int, input("Enter the array:").split()))
k = int(input("Enter the value of k: "))
heap = arr[:k]
heapq.heapify(heap)
for num in arr[k:]:
    if num > heap[0]:
        heapq.heapreplace(heap, num)
print(sorted(heap, reverse=True))
#for example:
# input: arr= 10,15,5
        #  k=2
# output: [15, 10]
