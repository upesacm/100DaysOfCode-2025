from collections import deque

def shortest_path_unweighted(vertices, edges, source):
    # Step 1 : Build adjacency list
    graph = [[] for _ in range(vertices)]
    for u, v in edges:
        graph[u].append(v)
        graph[v].append(u)  # Undirected graph

    # Step 2 : Initialize distances
    distance = [-1] * vertices
    distance[source] = 0

    # Step 3 : BFS
    q = deque([source])
    while q:
        node = q.popleft()
        for neighbour in graph[node]:
            if distance[neighbour] == -1:  # not visited
                distance[neighbour] = distance[node] + 1
                q.append(neighbour)

    return distance

try:
    vertices = int(input("Enter the number of vertices : "))
    edges_count = int(input("Enter the number of edges : "))
    edges = []
    print("Enter the vertices of each edge one by one, the two vertices being separated by spaces : ")
    for _ in range(edges_count):
        edge = list(map(int, input().split()))
        edges.append(edge)

    source = int(input("Enter the source : "))
    print(shortest_path_unweighted(vertices, edges, source))
except:
    print("Invalid input. Please try with a valid input.")
