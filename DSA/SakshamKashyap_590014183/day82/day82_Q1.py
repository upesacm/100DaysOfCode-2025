from collections import defaultdict

class Graph:
    def __init__(self):
        self.graph = defaultdict(list)
    
    def add_edge(self, u, v):
        """Add an edge to the graph"""
        self.graph[u].append(v)
        self.graph[v].append(u)  # For undirected graph
    
    def dfs(self, start, visited=None):
        """Depth First Search traversal"""
        if visited is None:
            visited = set()
        
        visited.add(start)
        result = [start]
        
        for neighbor in self.graph[start]:
            if neighbor not in visited:
                result.extend(self.dfs(neighbor, visited))
        
        return result
    
    def dfs_iterative(self, start):
        """Iterative DFS using stack"""
        visited = set()
        stack = [start]
        result = []
        
        while stack:
            node = stack.pop()
            if node not in visited:
                visited.add(node)
                result.append(node)
                # Add neighbors in reverse order to maintain left-to-right traversal
                for neighbor in reversed(self.graph[node]):
                    if neighbor not in visited:
                        stack.append(neighbor)
        
        return result

# Example usage and test cases:
if __name__ == "__main__":
    # Create a graph
    g = Graph()
    
    # Add edges (creating a simple graph)
    #     0
    #    / \
    #   1   2
    #  /   / \
    # 3   4   5
    g.add_edge(0, 1)
    g.add_edge(0, 2)
    g.add_edge(1, 3)
    g.add_edge(2, 4)
    g.add_edge(2, 5)
    
    print("Graph representation:")
    for vertex in g.graph:
        print(f"{vertex}: {g.graph[vertex]}")
    
    print("\nDFS traversal (recursive) starting from vertex 0:")
    dfs_result = g.dfs(0)
    print(dfs_result)
    
    print("\nDFS traversal (iterative) starting from vertex 0:")
    dfs_iterative_result = g.dfs_iterative(0)
    print(dfs_iterative_result)
    
    # Test with different starting points
    print("\nDFS from vertex 2:")
    print(g.dfs(2))
    
    # Test with disconnected components
    g2 = Graph()
    g2.add_edge(0, 1)
    g2.add_edge(2, 3)  # Disconnected component
    
    print("\nDFS on disconnected graph from vertex 0:")
    print(g2.dfs(0))
    print("DFS on disconnected graph from vertex 2:")
    print(g2.dfs(2))