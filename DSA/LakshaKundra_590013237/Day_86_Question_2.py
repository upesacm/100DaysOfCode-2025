def has_cycle_directed(vertices, edges):
    graph = {i: [] for i in range(vertices)}
    for u, v in edges:
        graph[u].append(v)
    visited = [0] * vertices
    def dfs(node):
        if visited[node] == 1:
            return True
        if visited[node] == 2:
            return False
        visited[node] = 1
        for nei in graph[node]:
            if dfs(nei):
                return True
        visited[node] = 2
        return False
    for i in range(vertices):
        if visited[i] == 0:
            if dfs(i):
                return True
    return False

# Example 1
print("Yes" if has_cycle_directed(3, [[0,1],[1,2],[2,0]]) else "No")  # Output: Yes

# Example 2
print("Yes" if has_cycle_directed(4, [[0,1],[1,2],[2,3]]) else "No")  # Output: No
