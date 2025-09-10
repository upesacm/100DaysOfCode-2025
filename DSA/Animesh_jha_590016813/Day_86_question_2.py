from collections import defaultdict

class DirectedGraph:
    def __init__(self, vertices):
        self.V = vertices
        self.graph = defaultdict(list)

    def add_edge(self, u, v):
        self.graph[u].append(v)

    def is_cyclic_util(self, v, visited, rec_stack):
        visited[v] = True
        rec_stack[v] = True

        for neighbor in self.graph[v]:
            if not visited[neighbor]:
                if self.is_cyclic_util(neighbor, visited, rec_stack):
                    return True
            elif rec_stack[neighbor]:
                
                return True

        rec_stack[v] = False
        return False

    def is_cyclic(self):
        visited = [False] * self.V
        rec_stack = [False] * self.V
        for i in range(self.V):
            if not visited[i]:
                if self.is_cyclic_util(i, visited, rec_stack):
                    return True
        return False

V = 3
edges = [[0, 1], [1, 2], [2, 0]]
g = DirectedGraph(V)
for u, v in edges:
    g.add_edge(u, v)

print("Yes" if g.is_cyclic() else "No") 
