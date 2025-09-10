from collections import defaultdict

class UndirectedGraph:
    def __init__(self, vertices):
        self.V = vertices
        self.graph = defaultdict(list)

    def add_edge(self, u, v):
        self.graph[u].append(v)
        self.graph[v].append(u)  

    def is_cyclic_util(self, v, visited, parent):
        visited[v] = True
        for neighbor in self.graph[v]:
            if not visited[neighbor]:
                if self.is_cyclic_util(neighbor, visited, v):
                    return True
            elif neighbor != parent:
               
                return True
        return False

    def is_cyclic(self):
        visited = [False] * self.V
        for i in range(self.V):
            if not visited[i]:
                if self.is_cyclic_util(i, visited, -1):
                    return True
        return False

V = 3
edges = [[0, 1], [1, 2], [2, 0]]
g = UndirectedGraph(V)
for u, v in edges:
    g.add_edge(u, v)

print("Yes" if g.is_cyclic() else "No")  
