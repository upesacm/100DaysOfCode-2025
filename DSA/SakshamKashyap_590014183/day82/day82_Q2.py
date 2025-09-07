from collections import defaultdict, deque

class Graph:
    def __init__(self):
        self.graph = defaultdict(list)
    
    def add_edge(self, u, v):
        """Add an edge to the graph"""
        self.graph[u].append(v)
        self.graph[v].append(u)  # For undirected graph
    
    def bfs(self, start):
        """Breadth First Search traversal"""
        visited = set()
        queue = deque([start])
        visited.add(start)
        result = []
        
        while queue:
            node = queue.popleft()
            result.append(node)
            
            # Add all unvisited neighbors to queue
            for neighbor in self.graph[node]:
                if neighbor not in visited:
                    visited.add(neighbor)
                    queue.append(neighbor)
        
        return result
    
    def bfs_level_order(self, start):
        """BFS with level information"""
        visited = set()
        queue = deque([(start, 0)])  # (node, level)
        visited.add(start)
        result = []
        
        while queue:
            node, level = queue.popleft()
            result.append((node, level))
            
            for neighbor in self.graph[node]:
                if neighbor not in visited:
                    visited.add(neighbor)
                    queue.append((neighbor, level + 1))
        
        return result
    
    def shortest_path(self, start, end):
        """Find shortest path between two nodes using BFS"""
        if start == end:
            return [start]
        
        visited = set()
        queue = deque([(start, [start])])
        visited.add(start)
        
        while queue:
            node, path = queue.popleft()
            
            for neighbor in self.graph[node]:
                if neighbor not in visited:
                    new_path = path + [neighbor]
                    if neighbor == end:
                        return new_path
                    
                    visited.add(neighbor)
                    queue.append((neighbor, new_path))
        
        return None  # No path found

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
    
    print("\nBFS traversal starting from vertex 0:")
    bfs_result = g.bfs(0)
    print(bfs_result)
    
    print("\nBFS with level information starting from vertex 0:")
    bfs_level_result = g.bfs_level_order(0)
    print(bfs_level_result)
    
    print("\nShortest path from 0 to 5:")
    path = g.shortest_path(0, 5)
    print(path)
    
    print("\nShortest path from 3 to 4:")
    path = g.shortest_path(3, 4)
    print(path)
    
    # Test with different starting points
    print("\nBFS from vertex 2:")
    print(g.bfs(2))
    
    # Test with disconnected components
    g2 = Graph()
    g2.add_edge(0, 1)
    g2.add_edge(2, 3)  # Disconnected component
    
    print("\nBFS on disconnected graph from vertex 0:")
    print(g2.bfs(0))
    
    print("Shortest path from 0 to 3 (disconnected):")
    print(g2.shortest_path(0, 3))  # Should return None