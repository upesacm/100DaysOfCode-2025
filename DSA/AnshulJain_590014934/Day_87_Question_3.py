n=int(input())
m=int(input())
edges=[list(map(int,input().split())) for _ in range(m)]
src=int(input())
dist=[float('inf')]*n
dist[src]=0
for _ in range(n-1):
    for u,v,w in edges:
        if dist[u]!=float('inf') and dist[v]>dist[u]+w:
            dist[v]=dist[u]+w
neg_cycle=False
for u,v,w in edges:
    if dist[u]!=float('inf') and dist[v]>dist[u]+w:
        neg_cycle=True
        break
if neg_cycle:
    print("Negative cycle detected")
else:
    print(dist)
