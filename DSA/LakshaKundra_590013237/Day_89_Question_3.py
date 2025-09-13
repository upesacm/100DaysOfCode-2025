def kosaraju(vertices, edges):
    graph = [[] for _ in range(vertices)]
    rev_graph = [[] for _ in range(vertices)]
    for u, v in edges:
        graph[u].append(v)
        rev_graph[v].append(u)
    visited = [False]*vertices
    order = []
    def dfs(u):
        visited[u] = True
        for v in graph[u]:
            if not visited[v]:
                dfs(v)
        order.append(u)
    for i in range(vertices):
        if not visited[i]:
            dfs(i)
    visited = [False]*vertices
    def rev_dfs(u):
        visited[u] = True
        for v in rev_graph[u]:
            if not visited[v]:
                rev_dfs(v)
    scc_count = 0
    for u in reversed(order):
        if not visited[u]:
            rev_dfs(u)
            scc_count += 1
    return scc_count

print(kosaraju(5, [[1,0],[0,2],[2,1],[0,3],[3,4]]))
print(kosaraju(4, [[0,1],[1,2],[2,3]]))
