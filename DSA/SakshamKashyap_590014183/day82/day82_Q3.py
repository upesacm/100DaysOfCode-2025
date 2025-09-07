from collections import defaultdict

class Graph:
    def __init__(self):
        self.graph = defaultdict(list)
        self.vertices = set()
    
    def add_edge(self, u, v):
        """Add an edge to the graph"""
        self.graph[u].append(v)
        self.graph[v].append(u)  # For undirected graph
        self.vertices.add(u)
        self.vertices.add(v)
    
    def dfs_connected_components(self, node, visited, component):
        """DFS to find all nodes in a connected component"""
        visited.add(node)
        component.append(node)
        
        for neighbor in self.graph[node]:
            if neighbor not in visited:
                self.dfs_connected_components(neighbor, visited, component)
    
    def find_connected_components(self):
        """Find all connected components in the graph"""
        visited = set()
        components = []
        
        for vertex in self.vertices:
            if vertex not in visited:
                component = []
                self.dfs_connected_components(vertex, visited, component)
                components.append(sorted(component))  # Sort for consistent output
        
        return components
    
    def count_connected_components(self):
        """Count the number of connected components"""
        return len(self.find_connected_components())
    
    def is_connected(self):
        """Check if the graph is connected (has only one component)"""
        return self.count_connected_components() <= 1
    
    def get_component_sizes(self):
        """Get the sizes of all connected components"""
        components = self.find_connected_components()
        return [len(component) for component in components]

def find_connected_components_matrix(adj_matrix):
    """Find connected components using adjacency matrix representation"""
    n = len(adj_matrix)
    visited = [False] * n
    components = []
    
    def dfs_matrix(node, component):
        visited[node] = True
        component.append(node)
        
        for neighbor in range(n):
            if adj_matrix[node][neighbor] == 1 and not visited[neighbor]:
                dfs_matrix(neighbor, component)
    
    for i in range(n):
        if not visited[i]:
            component = []
            dfs_matrix(i, component)
            components.append(sorted(component))
    
    return components

# Example usage and test cases:
if __name__ == "__main__":
    # Test Case 1: Graph with multiple connected components
    print("=== Test Case 1: Multiple Connected Components ===")
    g1 = Graph()
    
    # Component 1: 0-1-2
    g1.add_edge(0, 1)
    g1.add_edge(1, 2)
    
    # Component 2: 3-4
    g1.add_edge(3, 4)
    
    # Component 3: 5 (isolated node)
    g1.vertices.add(5)
    
    print("Graph edges:")
    for vertex in g1.graph:
        print(f"{vertex}: {g1.graph[vertex]}")
    
    components = g1.find_connected_components()
    print(f"\nConnected components: {components}")
    print(f"Number of components: {g1.count_connected_components()}")
    print(f"Component sizes: {g1.get_component_sizes()}")
    print(f"Is graph connected? {g1.is_connected()}")
    
    # Test Case 2: Connected graph
    print("\n=== Test Case 2: Connected Graph ===")
    g2 = Graph()
    g2.add_edge(0, 1)
    g2.add_edge(1, 2)
    g2.add_edge(2, 3)
    g2.add_edge(3, 0)
    
    print("Graph edges:")
    for vertex in g2.graph:
        print(f"{vertex}: {g2.graph[vertex]}")
    
    components2 = g2.find_connected_components()
    print(f"\nConnected components: {components2}")
    print(f"Number of components: {g2.count_connected_components()}")
    print(f"Is graph connected? {g2.is_connected()}")
    
    # Test Case 3: Using adjacency matrix
    print("\n=== Test Case 3: Adjacency Matrix Representation ===")
    # Matrix representation of graph with 2 components: {0,1,2} and {3,4}
    adj_matrix = [
        [0, 1, 1, 0, 0],  # Node 0 connected to 1,2
        [1, 0, 1, 0, 0],  # Node 1 connected to 0,2
        [1, 1, 0, 0, 0],  # Node 2 connected to 0,1
        [0, 0, 0, 0, 1],  # Node 3 connected to 4
        [0, 0, 0, 1, 0]   # Node 4 connected to 3
    ]
    
    print("Adjacency matrix:")
    for i, row in enumerate(adj_matrix):
        print(f"Node {i}: {row}")
    
    matrix_components = find_connected_components_matrix(adj_matrix)
    print(f"\nConnected components from matrix: {matrix_components}")
    print(f"Number of components: {len(matrix_components)}")
    
    # Test Case 4: Large graph with multiple components
    print("\n=== Test Case 4: Larger Graph ===")
    g3 = Graph()
    
    # Component 1: Star graph centered at 0
    for i in range(1, 5):
        g3.add_edge(0, i)
    
    # Component 2: Path graph 5-6-7-8
    g3.add_edge(5, 6)
    g3.add_edge(6, 7)
    g3.add_edge(7, 8)
    
    # Component 3: Triangle 9-10-11
    g3.add_edge(9, 10)
    g3.add_edge(10, 11)
    g3.add_edge(11, 9)
    
    components3 = g3.find_connected_components()
    print(f"Connected components: {components3}")
    print(f"Number of components: {g3.count_connected_components()}")
    print(f"Component sizes: {g3.get_component_sizes()}")
    
    # Demonstrate practical application
    print("\n=== Practical Application ===")
    print("This algorithm can be used for:")
    print("1. Social network analysis (finding friend groups)")
    print("2. Network connectivity analysis")
    print("3. Image processing (finding connected regions)")
    print("4. Circuit analysis (finding isolated components)")
    print("5. Web crawling (finding connected web pages)")