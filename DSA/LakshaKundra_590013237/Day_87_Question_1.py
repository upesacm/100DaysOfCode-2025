from collections import deque

def shortest_path(vertices, edges, source):
    graph = [[] for _ in range(vertices)]
    for u, v in edges:
        graph[u].append(v)
        graph[v].append(u)
    dist = [-1] * vertices
    dist[source] = 0
    q = deque([source])
    while q:
        node = q.popleft()
        for nei in graph[node]:
            if dist[nei] == -1:
                dist[nei] = dist[node] + 1
                q.append(nei)
    return dist

print(shortest_path(6, [[0,1],[0,2],[1,3],[2,4],[4,5]], 0))
print(shortest_path(4, [[0,1],[1,2],[2,3]], 0))
