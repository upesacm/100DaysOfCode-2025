import heapq

n=int(input())
m=int(input())
edges=[list(map(int,input().split())) for _ in range(m)]
src=int(input())
g=[[] for _ in range(n)]
for u,v,w in edges:
    g[u].append((v,w))
    g[v].append((u,w))
dist=[float('inf')]*n
dist[src]=0
pq=[(0,src)]
while pq:
    d,u=heapq.heappop(pq)
    if d>dist[u]:
        continue
    for v,w in g[u]:
        if dist[v]>d+w:
            dist[v]=d+w
            heapq.heappush(pq,(dist[v],v))
print(dist)
