n = int(input().strip())
m = int(input().strip())
edges = [list(map(int, input().split())) for _ in range(m)]

graph = [[] for _ in range(n)]
for u, v in edges:
    graph[u].append(v)
    graph[v].append(u)

visited = [False] * n
order = []

def dfs(node):
    visited[node] = True
    order.append(node)
    for neighbor in graph[node]:
        if not visited[neighbor]:
            dfs(neighbor)

dfs(0)
print(*order)
