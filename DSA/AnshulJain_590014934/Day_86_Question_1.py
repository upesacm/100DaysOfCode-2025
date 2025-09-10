def dfs(v, visited, parent, graph):
    visited[v] = True
    for u in graph[v]:
        if not visited[u]:
            if dfs(u, visited, v, graph):
                return True
        elif u != parent:
            return True
    return False

n = int(input())
m = int(input())
edges = [list(map(int, input().split())) for _ in range(m)]
graph = [[] for _ in range(n)]
for u, v in edges:
    graph[u].append(v)
    graph[v].append(u)
visited = [False]*n
cycle = False
for i in range(n):
    if not visited[i]:
        if dfs(i, visited, -1, graph):
            cycle = True
            break
print("Yes" if cycle else "No")
