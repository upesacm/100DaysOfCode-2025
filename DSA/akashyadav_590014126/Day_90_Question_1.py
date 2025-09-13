def has_hamiltonian_path(n, edges):
    from collections import defaultdict

    graph = defaultdict(list)
    for u, v in edges:
        graph[u].append(v)
        graph[v].append(u)

    def backtrack(v, visited, count):
        if count == n:
            return True
        for neighbor in graph[v]:
            if not visited[neighbor]:
                visited[neighbor] = True
                if backtrack(neighbor, visited, count + 1):
                    return True
                visited[neighbor] = False
        return False

    for start in range(n):
        visited = [False] * n
        visited[start] = True
        if backtrack(start, visited, 1):
            return True
    return False
