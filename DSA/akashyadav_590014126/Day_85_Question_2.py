from collections import defaultdict

def dfs_traversal(vertices, edges):
    graph = defaultdict(list)
    for u, v in edges:
        graph[u].append(v)
        graph[v].append(u)  

    visited = set()
    traversal = []

    def dfs(node):
        visited.add(node)
        traversal.append(node)
        for neighbor in graph[node]:
            if neighbor not in visited:
                dfs(neighbor)

    dfs(0)
    return traversal
