import heapq

def dijkstra(graph, start):
    distances = {}
    visited = set()

    for node in graph:
        distances[node] = float('inf')
    distances[start] = 0

    pq = [(0, start)]

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

#1.Missing optimization: The original code was missing a 'visited' check before processing each node from the priority queue.
#which causes the algorithm to potentially reprocess nodes and update their distances multiple times, leading to inefficiency[web:33].
#2.Why it works but is not optimal: The algorithm still updates distances correctly (with positive weights),
#but without the visited check, it can push redundant entries to the queue and revisit nodes unnecessarily[web:33].
#3.What it actually returns and why inefficient: The result is still correct shortest distances,
#but more time and memory are consumed due to redundant queue insertions and checks[web:33].
