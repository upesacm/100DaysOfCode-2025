from collections import deque

def is_bipartite(vertices, edges):
    graph = [[] for _ in range(vertices)]
    for u, v in edges:
        graph[u].append(v)
        graph[v].append(u)
    color = [-1] * vertices
    for start in range(vertices):
        if color[start] == -1:
            color[start] = 0
            q = deque([start])
            while q:
                node = q.popleft()
                for nei in graph[node]:
                    if color[nei] == -1:
                        color[nei] = 1 - color[node]
                        q.append(nei)
                    elif color[nei] == color[node]:
                        return "No"
    return "Yes"

print(is_bipartite(4, [[0,1],[1,2],[2,3],[3,0]]))
print(is_bipartite(3, [[0,1],[1,2],[2,0]]))

