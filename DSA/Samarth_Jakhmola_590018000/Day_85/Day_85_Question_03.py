def count_connected_components(vertices, edges):
    # Step 1 : Build an adjacency list (an array or dictionary of lists where each vertex store its neighbours)
    graph = [[] for _ in range(vertices)]
    for u, v in edges:
        graph[u].append(v)
        graph[v].append(u)   # Undirected graph

    visited = [False] * vertices
    components = 0

    # Step 2 : DFS to explore each component
    def DFS(node):
        visited[node] = True
        for neighbour in graph[node]:
            if not visited[neighbour]:
                DFS(neighbour)
                
    # Step 3 : Count components
    for i in range(vertices):
        if not visited[i]:
            DFS(i)
            components += 1

    return components

try:
    vertices = int(input("Enter the number of vertices : "))
    edges_count = int(input("Enter the number of edges : "))
    edges = []
    print("Enter the vertices of each edge one by one, the two vertices being separated by spaces : ")
    for _ in range(edges_count):
        edge = list(map(int, input().split()))
        edges.append(edge)

    print(count_connected_components(vertices, edges))
except:
    print("Invalid input. Please try with a valid input.")
