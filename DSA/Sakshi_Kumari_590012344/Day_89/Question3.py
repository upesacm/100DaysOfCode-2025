from collections import defaultdict

def kosaraju_scc(vertices, edges):
    graph = defaultdict(list)
    transpose_graph = defaultdict(list)

    for u, v in edges:
        graph[u].append(v)
        transpose_graph[v].append(u)

    visited = [False] * vertices
    finish_order = []

    def dfs_original(node):
        visited[node] = True
        for neighbor in graph[node]:
            if not visited[neighbor]:
                dfs_original(neighbor)
        finish_order.append(node)

    def dfs_transpose(node, component):
        visited[node] = True
        component.append(node)
        for neighbor in transpose_graph[node]:
            if not visited[neighbor]:
                dfs_transpose(neighbor, component)

    for v in range(vertices):
        if not visited[v]:
            dfs_original(v)

    visited = [False] * vertices
    scc_list = []

    for v in reversed(finish_order):
        if not visited[v]:
            component = []
            dfs_transpose(v, component)
            scc_list.append(component)

    return scc_list
