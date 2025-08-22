import heapq

h = []
for x in [5, 1, 10]:
    heapq.heappush(h, -x)
print(-heapq.heappop(h))

h = []
for x in [3, 7, 2, 9]:
    heapq.heappush(h, -x)
print(-heapq.heappop(h))
print(-heapq.heappop(h))
