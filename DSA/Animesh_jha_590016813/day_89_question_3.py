from collections import defaultdict

def kosaraju(n, edges):
    graph = defaultdict(list)
    rev_graph = defaultdict(list)
    for u,v in edges:
        graph[u].append(v)
        rev_graph[v].append(u)

    visited = [False] * n
    order = []

    def dfs(u):
        visited[u] = True
        for v in graph[u]:
            if not visited[v]:
                dfs(v)
        order.append(u)

    for i in range(n):
        if not visited[i]:
            dfs(i)

    visited = [False] * n
    def dfs_rev(u):
        visited[u] = True
        for v in rev_graph[u]:
            if not visited[v]:
                dfs_rev(v)

    scc_count = 0
    for u in reversed(order):
        if not visited[u]:
            dfs_rev(u)
            scc_count += 1
    return scc_count

edges = [[1,0],[0,2],[2,1],[0,3],[3,4]]
print("SCC count:", kosaraju(5, edges))  
