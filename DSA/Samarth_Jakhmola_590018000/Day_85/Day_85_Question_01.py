from collections import deque

def BFS_traversal(vertices, edges):
    # Step 1 : Build an adjacency list (an array or dictionary of lists where each vertex store its neighbours)
    graph = [[] for _ in range(vertices)]
    for u, v in edges:
        graph[u].append(v)
        graph[v].append(u)   # Undirected graph

    visited = [False] * vertices
    result = []

    # Step 2 : BFS using queue
    q = deque([0])
    visited[0] = True

    while q:
        node = q.popleft()
        result.append(node)

        for neighbour in graph[node]:
            if not visited[neighbour]:
                visited[neighbour] = True
                q.append(neighbour)

    return result

try:
    vertices = int(input("Enter the number of vertices : "))
    edges = []
    print("Enter the vertices of each edge one by one, the two vertices being separated by spaces : ")
    for _ in range(vertices - 1):
        edge = list(map(int, input().split()))
        edges.append(edge)

    nodes = BFS_traversal(vertices, edges)
    for _ in nodes:
        print(_, end = " ")
except:
    print("Invalid input. Please try with a valid input.")
