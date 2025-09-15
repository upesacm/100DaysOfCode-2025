from collections import deque

n=int(input())
m=int(input())
edges=[list(map(int,input().split())) for _ in range(m)]
src=int(input())
g=[[] for _ in range(n)]
for u,v in edges:
    g[u].append(v)
    g[v].append(u)
dist=[-1]*n
dist[src]=0
q=deque([src])
while q:
    u=q.popleft()
    for v in g[u]:
        if dist[v]==-1:
            dist[v]=dist[u]+1
            q.append(v)
print(dist)
