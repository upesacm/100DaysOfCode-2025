import heapq

def dijkstra(vertices, edges, source):
    graph = [[] for _ in range(vertices)]
    for u, v, w in edges:
        graph[u].append((v, w))

    distances = [float('inf')] * vertices
    distances[source] = 0

    min_heap = [(0, source)]
    while min_heap:
        dist_u, u = heapq.heappop(min_heap)
        if dist_u > distances[u]:
            continue
        for v, weight in graph[u]:
            if distances[v] > dist_u + weight:
                distances[v] = dist_u + weight
                heapq.heappush(min_heap, (distances[v], v))

    return distances
