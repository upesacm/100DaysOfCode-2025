# Your task: Implement recursive DFS using deep exploration to systematically visit all reachable nodes by going as deep as possible before backtracking.
def dfs_traversal():
    vertices_str = input("Enter the number of vertices: ")
    num_vertices = int(vertices_str)
    edges_str = input("Enter the edges as a list of pairs (e.g., [[0,1],[0,2],[1,3],[2,4]]): ")
    edges = eval(edges_str)
    
    adj = [[] for _ in range(num_vertices)]
    for u, v in edges:
        adj[u].append(v)
        adj[v].append(u)
    
    visited = [False] * num_vertices
    result = []
    
    def dfs(node):
        visited[node] = True
        result.append(node)
        for neighbor in adj[node]:
            if not visited[neighbor]:
                dfs(neighbor)
    
    dfs(0)
    print("Output:", "".join(map(str, result)))

dfs_traversal()
