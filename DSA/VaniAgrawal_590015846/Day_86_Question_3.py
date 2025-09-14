# Topological Sort (DFS)
def topo_sort(n, edges):
    from collections import defaultdict
    graph = defaultdict(list)
    for u, v in edges:
        graph[u].append(v)
    visited = [False] * n
    stack = []
    def dfs(node):
        visited[node] = True
        for neighbor in graph[node]:
            if not visited[neighbor]:
                dfs(neighbor)
        stack.append(node)
    for i in range(n):
        if not visited[i]:
            dfs(i)
    return stack[::-1]

n = int(input())
edges = eval(input())
order = topo_sort(n, edges)
print(*order)
