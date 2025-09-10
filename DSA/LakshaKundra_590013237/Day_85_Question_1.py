from collections import deque

def bfs(vertices, edges, start=0):
    graph = {i: [] for i in range(vertices)}
    for u, v in edges:
        graph[u].append(v)
        graph[v].append(u)
    visited = [False] * vertices
    q = deque([start])
    visited[start] = True
    result = []
    while q:
        node = q.popleft()
        result.append(node)
        for nei in graph[node]:
            if not visited[nei]:
                visited[nei] = True
                q.append(nei)
    return result

# Example 1
print(bfs(5, [[0,1],[0,2],[1,3],[2,4]]))  # Output: [0, 1, 2, 3, 4]

# Example 2
print(bfs(4, [[0,1],[1,2],[2,3]]))        # Output: [0, 1, 2, 3]
