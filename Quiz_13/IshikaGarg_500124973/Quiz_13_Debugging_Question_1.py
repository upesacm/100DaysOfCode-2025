Task 1: Identify the missing optimization
The missing optimization is:

if current_node in visited:
    continue
visited.add(current_node)
This ensures that once a node’s shortest distance is finalized (popped from the priority queue 
with the minimum distance), we never process it again.

Task 2: Why the algorithm still works but is not optimal
Even without the visited check, the algorithm still updates distances correctly because:
Every time a better distance is found, it pushes (new_dist, node) into the priority queue.
Eventually, the smallest distance gets popped and updates are propagated.
However, the same node can be added multiple times into the priority queue with different tentative distances.
So it still produces correct results, but wastes time processing duplicates.

Task 3: What does it actually return & why inefficient

It still returns the correct shortest distances:

{0: 0, 1: 3, 2: 1, 3: 4}

#corrected code:
import heapq

def dijkstra(graph, start):
    # graph is adjacency list: {node: [(neighbor, weight), ...]}
    distances = {}
    visited = set()

    # Initialize distances
    for node in graph:
        distances[node] = float('inf')
    distances[start] = 0

    # Priority queue: (distance, node)
    pq = [(0, start)]

    while pq:
        current_dist, current_node = heapq.heappop(pq)

        # Skip if this node is already finalized
        if current_node in visited:
            continue
        visited.add(current_node)

        # Explore neighbors
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

