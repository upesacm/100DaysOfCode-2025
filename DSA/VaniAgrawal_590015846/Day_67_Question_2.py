# Ropes with Minimum Cost
import heapq
arr = list(map(int, input().split()))
heapq.heapify(arr)
cost = 0
while len(arr) > 1:
    first = heapq.heappop(arr)
    second = heapq.heappop(arr)
    total = first + second
    cost += total
    heapq.heappush(arr, total)
print(cost)
