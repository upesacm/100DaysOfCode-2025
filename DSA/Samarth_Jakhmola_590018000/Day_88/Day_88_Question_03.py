from collections import deque

def is_bipartite(vertices, edges):
    # Build adjacency list
    graph = [[] for _ in range(vertices)]
    for u, v in edges:
        graph[u].append(v)
        graph[v].append(u)  # undirected graph

    # -1 means uncoloured, 0 and 1 are two colours
    colour = [-1] * vertices

    # Check all components
    for start in range(vertices):
        if colour[start] == -1:  # not visited
            queue = deque([start])
            colour[start] = 0  # assign first colour

            while queue:
                node = queue.popleft()
                for neighbour in graph[node]:
                    if colour[neighbour] == -1:
                        # Assign opposite colour
                        colour[neighbour] = 1 - colour[node]
                        queue.append(neighbour)
                    elif colour[neighbour] == colour[node]:
                        return False  # conflict found
    return True


vertices = int(input("Enter the number of vertices : "))
edges_count = int(input("Enter the number of edges : "))
edges = []
print("Enter the vertices of each edge separated by spaces : ")
for _ in range(edges_count):
    edges.append(list(map(int, input().split())))

print("Yes" if is_bipartite(vertices, edges) else "No")
