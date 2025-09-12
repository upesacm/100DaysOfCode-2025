def DFS(node, graph, visited, recursive_stack):
    visited[node] = True
    recursive_stack[node] = True

    for neighbour in graph[node]:
        if not visited[neighbour]:
            if DFS(neighbour, graph, visited, recursive_stack):
                return True
        elif recursive_stack[neighbour]:   # back edge -> Cycle
                return True
    
    recursive_stack[node] = False  # Remove from recursion stack
    return False

def detect_cycle_directed(vertices, edges):
    # Step 1 : Build adjacency list
    graph = [[] for _ in range(vertices)]
    for u, v in edges:
        graph[u].append(v)

    visited = [False] * vertices
    recursive_stack = [False] * vertices

    # Step 2 : DFS on each unvisited node
    for i in range(vertices):
        if not visited[i]:
            if DFS(i, graph, visited, recursive_stack):
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

    print("Yes" if detect_cycle_directed(vertices, edges) else "No")
except:
    print("Invalid input. Please try with a valid input.")
