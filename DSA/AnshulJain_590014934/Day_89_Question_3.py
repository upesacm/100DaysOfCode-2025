n, e = map(int, input().split())
graph = [[] for _ in range(n)]
transpose = [[] for _ in range(n)]

for _ in range(e):
    u, v = map(int, input().split())
    graph[u].append(v)
    transpose[v].append(u)

visited = [False] * n
order = []

def dfs(u):
    visited[u] = True
    for v in graph[u]:
        if not visited[v]:
            dfs(v)
    order.append(u)

for i in range(n):
    if not visited[i]:
        dfs(i)

visited = [False] * n
count = 0

def dfs_rev(u):
    visited[u] = True
    for v in transpose[u]:
        if not visited[v]:
            dfs_rev(v)

for u in reversed(order):
    if not visited[u]:
        dfs_rev(u)
        count += 1
print(count)
