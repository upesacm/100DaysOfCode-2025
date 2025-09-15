def bellman_ford(vertices, edges, source):
    distance = {}
    for v in vertices:
        distance[v] = float('inf')
    distance[source] = 0

    for _ in range(len(vertices) - 1):
        for u, v, w in edges:
            if distance[u] + w < distance[v]:
                distance[v] = distance[u] + w

    for u, v, w in edges:
        if distance[u] + w < distance[v]:
            return "Negative cycle detected"

    return distance
