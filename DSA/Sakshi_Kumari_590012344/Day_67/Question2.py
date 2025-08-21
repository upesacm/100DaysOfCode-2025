import heapq

def minCost(ropes):
    heapq.heapify(ropes)
    cost = 0
    while len(ropes) > 1:
        a = heapq.heappop(ropes)
        b = heapq.heappop(ropes)
        s = a + b
        cost += s
        heapq.heappush(ropes, s)
    return cost
