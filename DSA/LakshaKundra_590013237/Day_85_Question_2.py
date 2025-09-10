def dfs(vertices, edges, start=0):
    graph = {i: [] for i in range(vertices)}
    for u, v in edges:
        graph[u].append(v)
        graph[v].append(u)
    visited = [False] * vertices
    result = []
    def explore(node):
        visited[node] = True
        result.append(node)
        for nei in graph[node]:
            if not visited[nei]:
                explore(nei)
    explore(start)
    return result

# Example 1
print(dfs(5, [[0,1],[0,2],[1,3],[2,4]]))  # Output: [0, 1, 3, 2, 4]

# Example 2
print(dfs(4, [[0,1],[1,2],[2,3]]))        # Output: [0, 1, 2, 3]
