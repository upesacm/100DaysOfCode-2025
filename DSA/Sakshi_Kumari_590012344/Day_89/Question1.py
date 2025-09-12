class DisjointSet:
    def __init__(self, size):
        self.parent = [i for i in range(size)]
        self.rank = [0] * size

    def find_parent(self, node):
        if self.parent[node] != node:
            self.parent[node] = self.find_parent(self.parent[node])
        return self.parent[node]

    def union_nodes(self, node1, node2):
        root1 = self.find_parent(node1)
        root2 = self.find_parent(node2)

        if root1 == root2:
            return False

        if self.rank[root1] < self.rank[root2]:
            self.parent[root1] = root2
        elif self.rank[root1] > self.rank[root2]:
            self.parent[root2] = root1
        else:
            self.parent[root2] = root1
            self.rank[root1] += 1
        return True

def kruskal_algorithm(vertices, edge_list):
    edge_list.sort(key=lambda edge: edge[2])
    dsu = DisjointSet(vertices)
    total_weight = 0

    for u, v, weight in edge_list:
        if dsu.union_nodes(u, v):
            total_weight += weight

    return total_weight
