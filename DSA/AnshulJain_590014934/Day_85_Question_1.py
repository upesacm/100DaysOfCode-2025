from collections import deque

n = int(input().strip())
m = int(input().strip())
edges = [list(map(int, input().split())) for _ in range(m)]

graph = [[] for _ in range(n)]
for u, v in edges:
    graph[u].append(v)
    graph[v].append(u)

visited = [False] * n
queue = deque([0])
visited[0] = True
order = []

while queue:
    node = queue.popleft()
    order.append(node)
    for neighbor in graph[node]:
        if not visited[neighbor]:
            visited[neighbor] = True
            queue.append(neighbor)

print(*order)
