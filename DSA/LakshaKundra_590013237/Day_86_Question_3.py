def topo_sort(vertices, edges):
    graph = {i: [] for i in range(vertices)}
    for u, v in edges:
        graph[u].append(v)
    visited = [False] * vertices
    result = []
    def dfs(node):
        visited[node] = True
        for nei in graph[node]:
            if not visited[nei]:
                dfs(nei)
        result.append(node)
    for i in range(vertices):
        if not visited[i]:
            dfs(i)
    return result[::-1]

# Example 1
print(topo_sort(4, [[0,1],[0,2],[1,3],[2,3]]))  # Output: [0, 2, 1, 3] or [0, 1, 2, 3]

# Example 2
print(topo_sort(6, [[5,2],[5,0],[4,0],[4,1],[2,3],[3,1]]))  # Output: [4, 5, 2, 3, 1, 0] or similar
