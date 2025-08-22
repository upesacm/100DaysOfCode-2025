import heapq
from collections import Counter

arr = list(map(int, input().split()))
k = int(input())
count = Counter(arr)
heap = []

for num, freq in count.items():
    heapq.heappush(heap, (freq, num))
    if len(heap) > k:
        heapq.heappop(heap)

print([num for freq, num in heap])
#for example:
# input : 1 1 1 2 2 3
# k: 2
# output: [1, 2]