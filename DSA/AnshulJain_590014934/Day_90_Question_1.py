def hamiltonian_path_util(graph, v, visited, path, n):
    if len(path) == n:
        return True
    for u in graph[v]:
        if not visited[u]:
            visited[u] = True
            path.append(u)
            if hamiltonian_path_util(graph, u, visited, path, n):
                return True
            path.pop()
            visited[u] = False
    return False

def hamiltonian_path(graph, n):
    for start in range(n):
        visited = [False] * n
        visited[start] = True
        if hamiltonian_path_util(graph, start, visited, [start], n):
            return True
    return False

n = int(input())
m = int(input())
graph = [[] for _ in range(n)]
for _ in range(m):
    u, v = map(int, input().split())
    graph[u].append(v)
    graph[v].append(u)

print("Yes" if hamiltonian_path(graph, n) else "No")
