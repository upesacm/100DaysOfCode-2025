from collections import defaultdict

class Graph:
    def __init__(self, vertices):
        self.vertices = vertices
        self.graph = defaultdict(list)

    def add_edge(self, u, v):
        self.graph[u].append(v)

    # Step 1 : DFS to fill stack
    def DFS_fill(self, v, visited, stack):
        visited[v] = True
        for neighbour in self.graph[v]:
            if not visited[neighbour]:
                self.DFS_fill(neighbour, visited, stack)
        stack.append(v)

    # Step 2 : Transpose graph
    def transpose(self):
        trans_graph = Graph(self.vertices)
        for u in self.graph:
            for v in self.graph[u]:
                trans_graph.add_edge(v, u)
        return trans_graph
    
    # Step 3 : DFS on transpose graph
    def DFS_util(self, v, visited, component):
        visited[v] = True
        component.append(v)
        for neighbour in self.graph[v]:
            if not visited[neighbour]:
                self.DFS_util(neighbour, visited, component)

    def kosaraju_scc(self):
        stack = []
        visited = [False] * self.vertices

        # Step 1 : fill stack by finish times
        for i in range(self.vertices):
            if not visited[i]:
                self.DFS_fill(i, visited, stack)

        # Step 2 : transpose graph
        trans_graph = self.transpose()

        # Step 3 : process vertices in reverse finish order
        visited = [False] * self.vertices
        sccs = []

        while stack:
            v = stack.pop()
            if not visited[v]:
                component = []
                trans_graph.DFS_util(v, visited, component)
                sccs.append(component)

        return sccs

vertices = int(input("Enter the number of vertices : "))
edges_count = int(input("Enter the number of edges : "))
graph = Graph(vertices)
print("Enter the vertices of the edges one by one, separated by spaces : ")
for _ in range(edges_count):
    u, v = map(int, input().split())
    graph.add_edge(u, v)

sccs = graph.kosaraju_scc()    
print("Strongly Connected Components : ", sccs)
print("Total SCCs : ", len(sccs))
