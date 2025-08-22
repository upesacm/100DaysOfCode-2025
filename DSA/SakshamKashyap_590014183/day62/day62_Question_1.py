import heapq

def min_cost_to_connect_ropes(lengths):
    # Build a min-heap
    heapq.heapify(lengths)
    
    total_cost = 0
    
    # Keep combining until one rope remains
    while len(lengths) > 1:
        # Get two smallest ropes
        first = heapq.heappop(lengths)
        second = heapq.heappop(lengths)
        
        # Cost of connecting them
        cost = first + second
        total_cost += cost
        
        # Push new rope back
        heapq.heappush(lengths, cost)
    
    return total_cost

# Examples
print(min_cost_to_connect_ropes([4, 3, 2, 6]))  # 29
print(min_cost_to_connect_ropes([1, 2, 3, 4, 5]))  # 33
