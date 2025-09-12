def DFS(node, graph, visited, stack):
    visited[node] = True

    for neighbour in graph[node]:
        if not visited[neighbour]:
            DFS(neighbour, graph, visited, stack)
    stack.append(node)   #  Push after exploring all neighbours

def topological_sort(vertices, edges):
    # Step 1 : Build adjacency list
    graph = [[] for _ in range(vertices)]
    for u, v in edges:
        graph[u].append(v)

    visited = [False] * vertices
    stack = []

    # Step 2 : DFS for all unvisited nodes
    for i in range(vertices):
        if not visited[i]:
            DFS(i, graph, visited, stack)
            
    # Step 3 : Reverse stack to get ordering
    stack.reverse()
    return stack

try:
    vertices = int(input("Enter the number of vertices : "))
    edges_count = int(input("Enter the number of edges : "))
    edges = []
    print("Enter the vertices of each edge one by one, the two vertices being separated by spaces : ")
    for _ in range(edges_count):
        edge = list(map(int, input().split()))
        edges.append(edge)

    order = topological_sort(vertices, edges)
    print(*order)
except:
    print("Invalid input. Please try with a valid input.")
