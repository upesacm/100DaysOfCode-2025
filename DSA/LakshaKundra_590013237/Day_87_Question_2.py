import heapq

def dijkstra(vertices, edges, source):
    graph = [[] for _ in range(vertices)]
    for u, v, w in edges:
        graph[u].append((v, w))
        graph[v].append((u, w))
    dist = [float('inf')] * vertices
    dist[source] = 0
    pq = [(0, source)]
    while pq:
        d, node = heapq.heappop(pq)
        if d > dist[node]:
            continue
        for nei, w in graph[node]:
            if dist[node] + w < dist[nei]:
                dist[nei] = dist[node] + w
                heapq.heappush(pq, (dist[nei], nei))
    return dist

print(dijkstra(5, [[0,1,2],[0,2,4],[1,2,1],[2,3,7],[1,4,3]], 0))
print(dijkstra(3, [[0,1,5],[1,2,2]], 0))
