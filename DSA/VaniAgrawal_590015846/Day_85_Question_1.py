# Your task: Implement queue-based BFS using level-order exploration to systematically visit all reachable nodes in breadth-first manner from starting vertex.
from collections import deque

def bfs_traversal():
    vertices_str = input("Enter the number of vertices: ")
    num_vertices = int(vertices_str)
    edges_str = input("Enter the edges as a list of pairs (e.g., [[0,1],[0,2],[1,3],[2,4]]): ")
    edges = eval(edges_str)

    adj = [[] for _ in range(num_vertices)]
    for u, v in edges:
        adj[u].append(v)
        adj[v].append(u)

    queue = deque([0])
    visited = {0}
    result = []

    while queue:
        node = queue.popleft()
        result.append(node)
        for neighbor in adj[node]:
            if neighbor not in visited:
                visited.add(neighbor)
                queue.append(neighbor)

    print("Output:", "".join(map(str, result)))

bfs_traversal()
