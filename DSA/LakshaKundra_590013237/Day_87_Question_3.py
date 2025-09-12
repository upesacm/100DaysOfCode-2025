def bellman_ford(vertices, edges, source):
    dist = [float('inf')] * vertices
    dist[source] = 0
    for _ in range(vertices - 1):
        for u, v, w in edges:
            if dist[u] != float('inf') and dist[u] + w < dist[v]:
                dist[v] = dist[u] + w
    for u, v, w in edges:
        if dist[u] != float('inf') and dist[u] + w < dist[v]:
            return None
    return dist

print(bellman_ford(5, [[0,1,-1],[0,2,4],[1,2,3],[1,3,2],[1,4,2],[3,2,5],[3,1,1],[4,3,-3]], 0))
print(bellman_ford(3, [[0,1,5],[1,2,-2]], 0))
