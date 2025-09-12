def kosaraju(n, edges):
    from collections import defaultdict

    graph = defaultdict(list)
    transpose = defaultdict(list)
    for u, v in edges:
        graph[u].append(v)
        transpose[v].append(u)

    visited = [False] * n
    finish_order = []

    def dfs(u):
        visited[u] = True
        for v in graph[u]:
            if not visited[v]:
                dfs(v)
        finish_order.append(u)

    for i in range(n):
        if not visited[i]:
            dfs(i)

    visited = [False] * n
    def dfs_transpose(u):
        visited[u] = True
        for v in transpose[u]:
            if not visited[v]:
                dfs_transpose(v)

    scc_count = 0
    for u in reversed(finish_order):
        if not visited[u]:
            dfs_transpose(u)
            scc_count += 1

    return scc_count
