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
        
        # BUG FIX: Skip if we've already processed this node with a shorter distance
        # This optimization prevents redundant processing of nodes
        # Without this, the same node can be processed multiple times with different distances
        if current_dist > distances[current_node]:
            continue
            
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
# Expected: {0: 0, 1: 3, 2: 1, 3: 4}

# TASKS EXPLANATION:
# 1. The missing optimization is the check to skip processing a node if we've already
#    found a shorter path to it (current_dist > distances[current_node]).
# 2. The algorithm still works because it eventually finds the correct shortest paths
#    through the relaxation process, but it's inefficient due to redundant processing.
# 3. It returns the correct distances but might be inefficient because the same node
#    can be pushed into the priority queue multiple times, increasing operations.
