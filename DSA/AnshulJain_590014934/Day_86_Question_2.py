def dfs(v, graph, visited, recstack):
    visited[v] = True
    recstack[v] = True
    for u in graph[v]:
        if not visited[u]:
            if dfs(u, graph, visited, recstack):
                return True
        elif recstack[u]:
            return True
    recstack[v] = False
    return False

n = int(input())
m = int(input())
edges = [list(map(int, input().split())) for _ in range(m)]
graph = [[] for _ in range(n)]
for u, v in edges:
    graph[u].append(v)
visited = [False]*n
recstack = [False]*n
cycle = False
for i in range(n):
    if not visited[i]:
        if dfs(i, graph, visited, recstack):
            cycle = True
            break
print("Yes" if cycle else "No")
