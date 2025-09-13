def is_hamiltonian_path(graph):
    n = len(graph)
    visited = [False] * n

    def backtrack(path):
        if len(path) == n:
            return True
        for v in range(n):
            if not visited[v] and (not path or graph[path[-1]][v] == 1):
                visited[v] = True
                path.append(v)
                if backtrack(path):
                    return True
                path.pop()
                visited[v] = False
        return False

    for start in range(n):
        visited[start] = True
        if backtrack([start]):
            return True
        visited[start] = False
    return False
