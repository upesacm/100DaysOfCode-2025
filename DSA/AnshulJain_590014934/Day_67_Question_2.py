import heapq

def min_cost(ropes):
    heapq.heapify(ropes)
    cost = 0
    while len(ropes) > 1:
        first = heapq.heappop(ropes)
        second = heapq.heappop(ropes)
        total = first + second
        cost += total
        heapq.heappush(ropes, total)
    return cost

ropes = list(map(int, input("Enter rope lengths separated by space: ").split()))
print(min_cost(ropes))
