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

#Task Question
# Missing optimization: No check for already visited nodes after popping from the priority queue.
# Reason it still works: Relaxation ensures correct shortest distances, but nodes may be processed multiple times.
# Actual behavior: Returns correct distances {0: 0, 1: 3, 2: 1, 3: 4}, but inefficient since the same node can be re-pushed and re-processed many times.
