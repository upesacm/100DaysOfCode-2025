def DFS(node, parent, visited, graph):
    visited[node] = True
    for neighbour in graph[node]:
        if not visited[neighbour]:
            if DFS(neighbour, node, visited, graph):
                return True
        elif neighbour != parent:   # Visited but not parent -> Cycle
                return True
    return False

def detect_cycle(vertices, edges):
    # Step 1 : Build adjacency list
    graph = [[] for _ in range(vertices)]
    for u, v in edges:
        graph[u].append(v)
        graph[v].append(u)   # Undirected graph

    # Step 2 : Keep track of visited nodes
    visited = [False] * vertices

    # Step 3 : DFS on each unvisited node (for disconnected graphs)
    for i in range(vertices):
        if not visited[i]:
            if DFS(i, -1, visited, graph):
                return True
    return False

try:
    vertices = int(input("Enter the number of vertices : "))
    edges_count = int(input("Enter the number of edges : "))
    edges = []
    print("Enter the vertices of each edge one by one, the two vertices being separated by spaces : ")
    for _ in range(edges_count):
        edge = list(map(int, input().split()))
        edges.append(edge)

    print("Yes" if detect_cycle(vertices, edges) else "No")
except:
    print("Invalid input. Please try with a valid input.")
