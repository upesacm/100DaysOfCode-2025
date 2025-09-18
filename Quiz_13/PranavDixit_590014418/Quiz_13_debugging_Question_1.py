import heapq

def dijkstra(graph, start):
    V = len(graph)
    distances = {node: float('inf') for node in graph}
    visited = set()
    distances[start] = 0

    pq = [(0, start)]  # (distance, node)

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


if __name__ == "__main__":
    graph = {
        0: [(1, 4), (2, 1)],
        1: [(3, 1)],
        2: [(1, 2), (3, 5)],
        3: []
    }

    result = dijkstra(graph, 0)
    print("Shortest distances:", result)

"""
Answers 

1. The missing optimization in the buggy version:
   We never checked if a node was already visited. So, the same node
   could be inserted into the priority queue multiple times.

2. Why the old code still worked:
   Even if a node is pushed many times, the smaller distance eventually
   updates the table. That means the result is correct, just slower.

3. What it returned:
   It still gave correct shortest paths but did extra unnecessary work.
   The inefficiency comes from processing the same node multiple times.
"""
