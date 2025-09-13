class UnionFind:
    def __init__(self, n):
        self.parent = list(range(n))
        self.rank = [0] * n

    def find(self, x):
        if self.parent[x] != x:
            self.parent[x] = self.find(self.parent[x]) 
        return self.parent[x]

    def union(self, x, y):
        rootX, rootY = self.find(x), self.find(y)
        if rootX == rootY:
            return False
        if self.rank[rootX] < self.rank[rootY]:
            self.parent[rootX] = rootY
        elif self.rank[rootX] > self.rank[rootY]:
            self.parent[rootY] = rootX
        else:
            self.parent[rootY] = rootX
            self.rank[rootX] += 1
        return True

def kruskal(n, edges):
    edges.sort()
    uf = UnionFind(n)
    mst_cost = 0
    for w, u, v in edges:
        if uf.union(u, v):
            mst_cost += w
    return mst_cost

edges = [(10,0,1),(15,1,3),(6,0,2),(5,0,3),(4,2,3)]
print("Kruskal MST cost:", kruskal(4, edges)) 
