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

        # Skip this node if already visited
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
# Expected: {0: 0, 1: 3, 2: 1, 3: 4} 
