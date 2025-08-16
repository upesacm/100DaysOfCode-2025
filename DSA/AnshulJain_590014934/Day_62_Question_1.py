import heapq
ropes = list(map(int, input("Enter The array:- ").split())) # taking input for the array
heapq.heapify(ropes)
total_cost = 0
while len(ropes) > 1:
    first = heapq.heappop(ropes)
    second = heapq.heappop(ropes)
    cost = first + second
    total_cost += cost
    heapq.heappush(ropes, cost)
print(total_cost)
#for example:
# Input: 4 3 2 6
# Output: 29