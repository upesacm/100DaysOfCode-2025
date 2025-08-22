import heapq

def min_cost_to_connect_ropes(ropes):
    heapq.heapify(ropes)
    total_cost = 0
    while len(ropes) > 1:
        first = heapq.heappop(ropes)
        second = heapq.heappop(ropes)
        cost = first + second
        total_cost += cost
        heapq.heappush(ropes, cost)
    return total_cost

# Test cases
print(min_cost_to_connect_ropes([4, 3, 2, 6]))     # 29
print(min_cost_to_connect_ropes([1, 2, 3, 4, 5]))  # 33
