# Detect Cycle in Undirected Graph
def has_cycle(n, edges):
    from collections import defaultdict, deque
    graph = defaultdict(list)
    for u, v in edges:
        graph[u].append(v)
        graph[v].append(u)
    visited = [False] * n
    def dfs(node, parent):
        visited[node] = True
        for neighbor in graph[node]:
            if not visited[neighbor]:
                if dfs(neighbor, node):
                    return True
            elif neighbor != parent:
                return True
        return False
    for i in range(n):
        if not visited[i]:
            if dfs(i, -1):
                return True
    return False

n = int(input())
edges = eval(input())
print("Yes" if has_cycle(n, edges) else "No")
