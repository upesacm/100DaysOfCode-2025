def dfs_traversal(vertices, edges, start=0):
    graph = [[] for _ in range(vertices)]
    for u, v in edges:
        graph[u].append(v)
        graph[v].append(u)

    visited = [False] * vertices
    dfs_order = []

    def dfs(node):
        visited[node] = True
        dfs_order.append(node)
        for neighbor in graph[node]:
            if not visited[neighbor]:
                dfs(neighbor)

    dfs(start)
    return dfs_order

print("DFS Example 1:", dfs_traversal(5, [[0,1],[0,2],[1,3],[2,4]]))  
print("DFS Example 2:", dfs_traversal(4, [[0,1],[1,2],[2,3]]))
