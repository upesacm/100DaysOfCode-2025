def count_connected_components(vertices, edges):
    graph = [[] for _ in range(vertices)]
    for u, v in edges:
        graph[u].append(v)
        graph[v].append(u)

    visited = [False] * vertices
    count = 0

    def dfs(node):
        visited[node] = True
        for neighbor in graph[node]:
            if not visited[neighbor]:
                dfs(neighbor)

    for i in range(vertices):
        if not visited[i]:
            count += 1
            dfs(i)

    return count

print("Components Example 1:", count_connected_components(5, [[0,1],[1,2],[3,4]]))  
print("Components Example 2:", count_connected_components(4, [[0,1],[2,3]]))
