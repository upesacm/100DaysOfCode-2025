def has_cycle_directed(vertices, edges):
    from collections import defaultdict

    graph = defaultdict(list)
    for u, v in edges:
        graph[u].append(v)

    visited = [False] * vertices
    rec_stack = [False] * vertices

    def dfs(node):
        visited[node] = True
        rec_stack[node] = True

        for neighbor in graph[node]:
            if not visited[neighbor]:
                if dfs(neighbor):
                    return True
            elif rec_stack[neighbor]:
                return True

        rec_stack[node] = False
        return False

    for v in range(vertices):
        if not visited[v]:
            if dfs(v):
                return "Yes"
    return "No"
