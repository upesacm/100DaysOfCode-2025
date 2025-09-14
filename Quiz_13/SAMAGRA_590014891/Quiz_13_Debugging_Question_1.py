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

        # ----------------- FIXED BUG -----------------
        # Missing optimization:
        # If the current node is already visited, skip it.
        # Without this, we may process the same node multiple times,
        # leading to inefficiency although the result is still correct.
        if current_node in visited:
            continue
        visited.add(current_node)
        # ---------------------------------------------

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
print(f"Shortest distances: {result}")  # Expected: {0: 0, 1: 3, 2: 1, 3: 4}


# ------------------- TASK ANSWERS -------------------

# 1. Identify the missing optimization that causes inefficiency:
#    The algorithm does not check whether a node has already been visited.
#    This means the same node can be added to the priority queue multiple times.

# 2. Explain why the algorithm still works but is not optimal:
#    It still works because every time a shorter path is found, it updates
#    the distance correctly. However, without the "visited" check,
#    redundant paths may get processed, which increases the number of
#    unnecessary extractions from the heap.

# 3. What does it actually return and why might it be inefficient?
#    It still returns the correct shortest distances for all nodes.
#    The inefficiency arises because the priority queue may contain
#    multiple entries for the same node, causing extra processing.
#    This makes the algorithm slower than the optimal O((V + E) log V).
