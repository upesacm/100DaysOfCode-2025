import heapq

def n_ropes_min_cost(ropes):
    # Convert list into a min-heap
    heapq.heapify(ropes)

    total_cost = 0

    # Keep connecting ropes until one remains
    while len(ropes) > 1:
        # Pop two smallest ropes
        first = heapq.heappop(ropes)
        second = heapq.heappop(ropes)

        # Cost to connect them
        cost = first + second
        total_cost += cost

        # Push the new rope back into the heap
        heapq.heappush(ropes, cost)

    return total_cost

try:
    ropes = list(map(int, input("Enter the lengths of the ropes separated by spaces : ").split()))
    print(n_ropes_min_cost(ropes))
except:
    print("Invalid input. Please try with a valid input.") 
