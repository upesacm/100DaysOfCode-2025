from collections import deque

def bfs_shortest_path(vertices, edges, source):
    graph = [[] for _ in range(vertices)]
    for u, v in edges:
        graph[u].append(v)
        graph[v].append(u)  

    distances = [-1] * vertices
    distances[source] = 0

    queue = deque([source])
    while queue:
        node = queue.popleft()
        for neighbor in graph[node]:
            if distances[neighbor] == -1:
                distances[neighbor] = distances[node] + 1
                queue.append(neighbor)

    return distances
