def bellman_ford(vertices, edges, source):
    distances = [float('inf')] * vertices
    distances[source] = 0

    for _ in range(vertices - 1):
        for u, v, w in edges:
            if distances[u] != float('inf') and distances[v] > distances[u] + w:
                distances[v] = distances[u] + w

    # Optional: Detect negative cycles
    for u, v, w in edges:
        if distances[u] != float('inf') and distances[v] > distances[u] + w:
            raise ValueError("Negative weight cycle detected")

    return distances
