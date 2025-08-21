import heapq

def min_cost(ropes):
    heapq.heapify(ropes)
    cost = 0
    while len(ropes) > 1:
        a = heapq.heappop(ropes)
        b = heapq.heappop(ropes)
        s = a + b
        cost += s
        heapq.heappush(ropes, s)
    return cost

print(min_cost([4,3,2,6]))
print(min_cost([1,2,3,4,5]))
