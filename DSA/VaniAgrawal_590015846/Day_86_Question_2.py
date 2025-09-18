# Detect Cycle in Directed Graph
def has_cycle(n, edges):
    from collections import defaultdict
    graph = defaultdict(list)
    for u, v in edges:
        graph[u].append(v)
    visited = [0] * n  # 0=unvisited, 1=visiting, 2=visited
    def dfs(node):
        if visited[node] == 1:
            return True
        if visited[node] == 2:
            return False
        visited[node] = 1
        for neighbor in graph[node]:
            if dfs(neighbor):
                return True
        visited[node] = 2
        return False
    for i in range(n):
        if visited[i] == 0:
            if dfs(i):
                return True
    return False

n = int(input())
edges = eval(input())
print("Yes" if has_cycle(n, edges) else "No")
