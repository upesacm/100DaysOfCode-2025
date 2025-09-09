def count_components(vertices, edges):
    graph = {i: [] for i in range(vertices)}
    for u, v in edges:
        graph[u].append(v)
        graph[v].append(u)
    visited = [False] * vertices
    def dfs(node):
        visited[node] = True
        for nei in graph[node]:
            if not visited[nei]:
                dfs(nei)
    count = 0
    for i in range(vertices):
        if not visited[i]:
            dfs(i)
            count += 1
    return count

# Example 1
print(count_components(5, [[0,1],[1,2],[3,4]]))  # Output: 2

# Example 2
print(count_components(4, [[0,1],[2,3]]))        # Output: 2
