from collections import defaultdict

def count_connected_components(vertices, edges):
    graph = defaultdict(list)
    for u, v in edges:
        graph[u].append(v)
        graph[v].append(u) 

    visited = set()
    component_count = 0

    def dfs(node):
        visited.add(node)
        for neighbor in graph[node]:
            if neighbor not in visited:
                dfs(neighbor)

    for node in range(vertices):
        if node not in visited:
            dfs(node)
            component_count += 1

    return component_count
