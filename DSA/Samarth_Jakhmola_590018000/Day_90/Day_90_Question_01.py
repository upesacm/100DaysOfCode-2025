def hamiltonian_path_exists(vertices, edges):
    # Step 1 : Build adjacency list
    graph = [[] for _ in range(vertices)]
    for u, v in edges:
        graph[u].append(v)
        graph[v].append(u)   # undirected graph

    def backtrack(node, visited_count, visited):
        # If visited all vertices -> path found
        if visited_count == vertices:
            return True
        
        for neighbour in graph[node]:
            if not visited[neighbour]:
                visited[neighbour] = True
                if backtrack(neighbour, visited_count + 1, visited):
                    return True 
                visited = False   # backtrack 

        return False
    
    # Try starting from each vertex 
    for start in range(vertices):
        visited = [False] * vertices
        visited[start] = True
        if backtrack(start, 1, visited):
            return "Yes"
        
    return "No"

try:
    vertices = int(input("Enter the number of vertices : "))
    edges_count = int(input("Enter the number of edges : "))
    edges = []

    print("Enter the vertices of each edge one by one, separated by spaces : ")
    for _ in range(edges_count):
        edges.append(list(map(int, input().split())))

    print(hamiltonian_path_exists(vertices, edges))
except:
    print("Invalid input. Please try with a valid input.")
