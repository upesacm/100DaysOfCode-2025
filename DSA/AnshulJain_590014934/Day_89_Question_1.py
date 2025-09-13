def find(parent, i):
    if parent[i] != i:
        parent[i] = find(parent, parent[i])
    return parent[i]

def union(parent, rank, x, y):
    xr, yr = find(parent, x), find(parent, y)
    if rank[xr] < rank[yr]:
        parent[xr] = yr
    elif rank[xr] > rank[yr]:
        parent[yr] = xr
    else:
        parent[yr] = xr
        rank[xr] += 1

v, e = map(int, input().split())
edges = []
for _ in range(e):
    u, v2, w = map(int, input().split())
    edges.append((w, u, v2))

edges.sort()
parent = [i for i in range(v)]
rank = [0] * v
mst = 0
for w, u, v2 in edges:
    if find(parent, u) != find(parent, v2):
        union(parent, rank, u, v2)
        mst += w
print(mst)
