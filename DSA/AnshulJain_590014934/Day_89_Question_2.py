import heapq

n, e = map(int, input().split())
graph = [[] for _ in range(n)]
for _ in range(e):
    u, v, w = map(int, input().split())
    graph[u].append((w, v))
    graph[v].append((w, u))

visited = [False] * n
pq = [(0, 0)]
total = 0

while pq:
    w, u = heapq.heappop(pq)
    if visited[u]:
        continue
    visited[u] = True
    total += w
    for wt, v in graph[u]:
        if not visited[v]:
            heapq.heappush(pq, (wt, v))

print(total)
