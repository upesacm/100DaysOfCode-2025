def has_cycle(vertices, edges):
    graph = {i: [] for i in range(vertices)}
    for u, v in edges:
        graph[u].append(v)
        graph[v].append(u)
    visited = [False] * vertices
    def dfs(node, parent):
        visited[node] = True
        for nei in graph[node]:
            if not visited[nei]:
                if dfs(nei, node):
                    return True
            elif nei != parent:
                return True
        return False
    for i in range(vertices):
        if not visited[i]:
            if dfs(i, -1):
                return True
    return False

# Example 1
print("Yes" if has_cycle(3, [[0,1],[1,2],[2,0]]) else "No")  # Output: Yes

# Example 2
print("Yes" if has_cycle(3, [[0,1],[1,2]]) else "No")        # Output: No
