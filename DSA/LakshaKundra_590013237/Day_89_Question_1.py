def kruskal(vertices, edges):
    parent = list(range(vertices))
    rank = [0]*vertices
    def find(x):
        if parent[x] != x:
            parent[x] = find(parent[x])
        return parent[x]
    def union(x, y):
        rx, ry = find(x), find(y)
        if rx != ry:
            if rank[rx] < rank[ry]:
                parent[rx] = ry
            elif rank[rx] > rank[ry]:
                parent[ry] = rx
            else:
                parent[ry] = rx
                rank[rx] += 1
            return True
        return False
    edges.sort(key=lambda x: x[2])
    mst_cost = 0
    for u, v, w in edges:
        if union(u, v):
            mst_cost += w
    return mst_cost

print(kruskal(4, [[0,1,10],[0,2,6],[0,3,5],[2,3,4],[1,3,15]]))
print(kruskal(3, [[0,1,1],[1,2,2],[0,2,3]]))
