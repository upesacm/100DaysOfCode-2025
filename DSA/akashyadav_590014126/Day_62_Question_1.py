import heapq

def min_cost_to_connect(ropes):
    heapq.heapify(ropes)
    total_cost = 0

    while len(ropes) > 1:
        first = heapq.heappop(ropes)
        second = heapq.heappop(ropes)
        cost = first + second
        total_cost += cost
        heapq.heappush(ropes, cost)

    return total_cost

#example
print(min_cost_to_connect([12, 23, 43, 64, 85]))
