from collections import deque

def shortest_path(graph, source):
    n = len(graph)
    dist = [-1] * n
    dist[source] = 0
    q = deque([source])
    while q:
        u = q.popleft()
        for v in graph[u]:
            if dist[v] == -1:
                dist[v] = dist[u] + 1
                q.append(v)
    return dist
