import heapq

def dijkstra(graph, start):
    distances = {node: float('inf') for node in graph}
    distances[start] = 0
    pq = [(0, start)] 
    visited = set()

    while pq:
        current_dist, current_node = heapq.heappop(pq)

        if current_node in visited:
            continue
        
        visited.add(current_node)

        for neighbor, weight in graph[current_node]:
            new_dist = current_dist + weight
            if new_dist < distances[neighbor]:
                distances[neighbor] = new_dist
                heapq.heappush(pq, (new_dist, neighbor))
    
    return distances

# Test case:
graph = {
    0: [(1, 4), (2, 1)],
    1: [(3, 1)],
    2: [(1, 2), (3, 5)],
    3: []
}

result = dijkstra(graph, 0)
print(f"Shortest distances: {result}")

# Tasks:
# 1. Identify the missing optimization that causes inefficiency.
# The original code lacked the 'visited' set and the check `if current_node in visited: continue`. 
# Without this, the algorithm re-processes nodes with outdated (longer) distances, 
# leading to unnecessary heap operations and wasted time. The corrected code adds this
# optimization to ensure each node is processed only once with its minimum distance.

# 2. Explain why the algorithm still works but is not optimal.
# The algorithm still works because a priority queue (min-heap) always extracts the 
# minimum-distance node first. Therefore, the first time a node is popped, its distance 
# is guaranteed to be the shortest. The bug simply adds extra, unneeded entries to the 
# priority queue. When those outdated entries are eventually popped, the check 
# `new_dist < distances[neighbor]` would implicitly fail (if implemented correctly) 
# or they would be skipped by the added `visited` check.

# 3. What does it actually return and why might it be inefficient?
# The original code returns the correct shortest distances, but due to a bug in the 
# `if` condition (it used assignment `=` instead of comparison `<`) it would have 
# incorrect results. The provided corrected code will return the correct shortest 
# distances. However, the inefficiency stems from the fact that without the `visited` 
# set, multiple entries for the same node, each with a different distance, might exist 
# in the priority queue, bloating its size and slowing down the `heappop` operation.
