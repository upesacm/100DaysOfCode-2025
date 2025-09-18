from collections import deque, defaultdict

def bfs_traversal(vertices, edges):
    graph = defaultdict(list)
    for u, v in edges:
        graph[u].append(v)
        graph[v].append(u) 

    visited = set()
    queue = deque()
    traversal = []

    queue.append(0)
    visited.add(0)

    while queue:
        current = queue.popleft()
        traversal.append(current)

        for neighbor in graph[current]:
            if neighbor not in visited:
                visited.add(neighbor)
                queue.append(neighbor)

    return traversal
