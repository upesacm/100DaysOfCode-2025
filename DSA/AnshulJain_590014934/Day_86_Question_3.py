def dfs(v, graph, visited, order):
    visited[v] = True
    for u in graph[v]:
        if not visited[u]:
            dfs(u, graph, visited, order)
    order.append(v)

n = int(input())
m = int(input())
edges = [list(map(int, input().split())) for _ in range(m)]
graph = [[] for _ in range(n)]
for u, v in edges:
    graph[u].append(v)
visited = [False]*n
order = []
for i in range(n):
    if not visited[i]:
        dfs(i, graph, visited, order)
print(*order[::-1])
