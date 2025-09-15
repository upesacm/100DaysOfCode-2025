from collections import defaultdict

class Graph:
    def __init__(self, vertices):
        self.vertices = vertices
        self.graph = defaultdict(list)

    def add_edge(self, u, v):
        self.graph[u].append(v)
        self.graph[v].append(u)

    def has_cycle_util(self, v, visited, parent):
        visited[v] = True
        for neighbor in self.graph[v]:
            if not visited[neighbor]:
                if self.has_cycle_util(neighbor, visited, v):
                    return True
            elif neighbor != parent:
                return True
        return False

    def has_cycle(self):
        visited = [False] * self.vertices
        for i in range(self.vertices):
            if not visited[i]:
                if self.has_cycle_util(i, visited, -1):
                    return True
        return False
