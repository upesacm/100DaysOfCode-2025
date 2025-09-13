def has_cycle_dfs(vertices, edges):
    from collections import defaultdict

    graph = defaultdict(list)
    for u, v in edges:
        graph[u].append(v)
        graph[v].append(u)

    visited = [False] * vertices

    def dfs(node, parent):
        visited[node] = True
        for neighbor in graph[node]:
            if not visited[neighbor]:
                if dfs(neighbor, node):
                    return True
            elif neighbor != parent:
                return True
        return False

    for v in range(vertices):
        if not visited[v]:
            if dfs(v, -1):
                return "Yes"
    return "No"
