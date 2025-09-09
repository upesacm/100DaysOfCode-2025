n = int(input().strip())
m = int(input().strip())
edges = [list(map(int, input().split())) for _ in range(m)]

graph = [[] for _ in range(n)]
for u, v in edges:
    graph[u].append(v)
    graph[v].append(u)
visited = [False] * n
def dfs(node):
    visited[node] = True
    for neighbor in graph[node]:
        if not visited[neighbor]:
            dfs(neighbor)
count = 0
for i in range(n):
    if not visited[i]:
        dfs(i)
        count += 1
print(count)
