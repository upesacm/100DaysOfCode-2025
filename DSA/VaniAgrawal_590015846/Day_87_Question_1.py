# Your task: Implement BFS-based shortest path calculation using level-wise exploration to compute minimum distances from source to all reachable vertices.
from collections import deque

def shortest_path_unweighted_graph():
    num_vertices = int(input("Enter the number of vertices: "))
    edges = eval(input("Enter the edges as a list of lists, e.g., [[0,1],[0,2]]: "))
    source = int(input("Enter the source vertex: "))

    adj = [[] for _ in range(num_vertices)]
    for u, v in edges:
        adj[u].append(v)
        adj[v].append(u)

    distances = [-1] * num_vertices
    distances[source] = 0
    queue = deque([source])

    while queue:
        u = queue.popleft()
        for v in adj[u]:
            if distances[v] == -1:
                distances[v] = distances[u] + 1
                queue.append(v)

    print("Distances =", distances)

shortest_path_unweighted_graph()
