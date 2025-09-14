def hamiltonian_path(graph, n):
    def backtrack(path, visited):
        if len(path) == n:
            return True
        for v in range(n):
            if not visited[v] and (not path or v in graph[path[-1]]):
                visited[v] = True
                path.append(v)
                if backtrack(path, visited):
                    return True
                path.pop()
                visited[v] = False
        return False
    for start in range(n):
        visited = [False] * n
        visited[start] = True
        if backtrack([start], visited):
            return True
    return False

n = 4
edges = [[0,1],[1,2],[2,3],[3,0]]
graph = {i: [] for i in range(n)}
for u,v in edges:
    graph[u].append(v)
    graph[v].append(u)
print("Yes" if hamiltonian_path(graph,n) else "No")

n = 3
edges = [[0,1],[1,2]]
graph = {i: [] for i in range(n)}
for u,v in edges:
    graph[u].append(v)
    graph[v].append(u)
print("Yes" if hamiltonian_path(graph,n) else "No")
