#Implement greedy rope connection using min-heap to always select shortest ropes for combination, achieving optimal cost minimization.
import heapq
def min_cost_ropes(ropes):
    heapq.heapify(ropes)
    cost = 0
    while len(ropes) > 1:
        a = heapq.heappop(ropes)
        b = heapq.heappop(ropes)
        cost += a + b
        heapq.heappush(ropes, a + b)
    return cost

ropes = list(map(int, input("Enter rope lengths: ").split()))
print(min_cost_ropes(ropes))
