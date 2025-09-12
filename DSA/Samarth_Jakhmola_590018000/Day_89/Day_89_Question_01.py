class DisjointSet:
    def __init__(self, n):
        self.parent = [i for i in range(n)]
        self.rank = [0] * n

    def find(self, x):
        if self.parent[x] != x:
            self.parent[x] = self.find(self.parent[x])  # Path compression
        return self.parent[x]
    
    def union(self, x, y):
        rootX = self.find(x)
        rootY = self.find(y)

        if rootX != rootY:
            if self.rank[rootX] < self.rank[rootY]:
                self.parent[rootX] = rootY
            elif self.rank[rootX] > self.rank[rootY]:
                self.parent[rootY] = rootX
            else:
                self.parent[rootY] = rootX
                self.rank[rootX] += 1
            return True
        return False
    
def kruskal_MST(vertices, edges):
    # Sort edges by weight 
    edges.sort(key = lambda x : x[2])

    dsu = DisjointSet(vertices)
    mst_weight = 0
    mst_edges = []

    for u, v, w in edges:
        if dsu.union(u, v):   # if edge connects two different sets
            mst_weight += w
            mst_edges.append((u, v, w))

        if len(mst_edges) == vertices - 1:
            break

    return mst_weight, mst_edges

try:
    vertices = int(input("Enter the number of vertices : "))
    edges_count = int(input("Enter the number of edges : "))
    edges = []
    print("Enter the vertices of the edge with their weight (source destination weight), separated by spaces : ")
    for _ in range(edges_count):
        u, v, w = map(int, input().split())
        edges.append((u, v, w))

    mst_weight, mst_edges = kruskal_MST(vertices, edges)
    print("Minimum Spanning Tree cost : ", mst_weight)
    print("Edges in MST : ", mst_edges)
except:
    print("Invalid input. Please try with a valid input.") 
