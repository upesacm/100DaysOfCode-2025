# Your task: Implement backtracking-based Hamiltonian path detection to check if graph contains a path visiting all vertices exactly once.
def has_hamiltonian_path():
    num_vertices = int(input("Enter the number of vertices: "))
    edges_str = input("Enter the edges as a list of lists, e.g., [[0,1],[1,2],[2,3],[3,0]]: ")
    edges = eval(edges_str)
    
    adj = [[] for _ in range(num_vertices)]
    for u, v in edges:
        adj[u].append(v)
        adj[v].append(u)
    
    path = []
    visited = [False] * num_vertices

    def find_path(u):
        visited[u] = True
        path.append(u)

        if len(path) == num_vertices:
            return True

        for v in adj[u]:
            if not visited[v]:
                if find_path(v):
                    return True
        
        path.pop()
        visited[u] = False
        return False

    for i in range(num_vertices):
        if find_path(i):
            print("Output: Yes")
            return
    
    print("Output: No")

has_hamiltonian_path()
