# Your task: Implement component counting using traversal-based or union-find approach to identify and count all disconnected regions in undirected graph.
from collections import deque

def count_connected_components():
    vertices_str = input("Enter the number of vertices: ")
    num_vertices = int(vertices_str)
    edges_str = input("Enter the edges as a list of pairs (e.g., [[0,1],[1,2],[3,4]]): ")
    edges = eval(edges_str)

    adj = [[] for _ in range(num_vertices)]
    for u, v in edges:
        adj[u].append(v)
        adj[v].append(u)
    
    visited = [False] * num_vertices
    count = 0
    
    for i in range(num_vertices):
        if not visited[i]:
            count += 1
            queue = deque([i])
            visited[i] = True
            while queue:
                node = queue.popleft()
                for neighbor in adj[node]:
                    if not visited[neighbor]:
                        visited[neighbor] = True
                        queue.append(neighbor)
    
    print("Output:", count)

count_connected_components()
