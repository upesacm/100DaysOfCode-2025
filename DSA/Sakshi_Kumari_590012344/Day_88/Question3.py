from collections import deque

def is_bipartite(graph):
    n = len(graph)
    color = [-1] * n  

    for start in range(n):
        if color[start] == -1:
            queue = deque([start])
            color[start] = 0

            while queue:
                node = queue.popleft()
                for neighbor in graph[node]:
                    if color[neighbor] == -1:
                        color[neighbor] = 1 - color[node]
                        queue.append(neighbor)
                    elif color[neighbor] == color[node]:
                        return False
    return True
