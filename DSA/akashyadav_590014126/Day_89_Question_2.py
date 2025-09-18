class UnionFind:
    def __init__(self, n):
        self.parent = list(range(n))
        self.rank = [0] * n

    def find(self, u):
        if self.parent[u] != u:
            self.parent[u] = self.find(self.parent[u])  
        return self.parent[u]

    def union(self, u, v):
        pu, pv = self.find(u), self.find(v)
        if pu == pv:
            return False
        if self.rank[pu] < self.rank[pv]:
            self.parent[pu] = pv
        else:
            self.parent[pv] = pu
            if self.rank[pu] == self.rank[pv]:
                self.rank[pu] += 1
        return True

def kruskal(n, edges):
    edges.sort(key=lambda x: x[2])  
    uf = UnionFind(n)
    mst_cost = 0
    for u, v, w in edges:
        if uf.union(u, v):
            mst_cost += w
    return mst_cost
