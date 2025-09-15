from collections import deque

def bfs_shortest_path(graph, source):
    distance = {}
    for node in graph:
        distance[node] = -1 
    distance[source] = 0

    queue = deque()
    queue.append(source)

    while queue:
        current = queue.popleft()

        for neighbor in graph[current]:
            if distance[neighbor] == -1:
                distance[neighbor] = distance[current] + 1
                queue.append(neighbor)

    return distance
