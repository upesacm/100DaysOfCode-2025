def eulerian_path_circuit(graph):
    n = len(graph)
    degree = [0] * n
    for u in range(n):
        for v in range(n):
            if graph[u][v] == 1:
                degree[u] += 1
    odd_count = sum(1 for d in degree if d % 2 == 1)
    if odd_count == 0:
        return "Eulerian Circuit exists"
    elif odd_count == 2:
        return "Eulerian Path exists"
    else:
        return "Neither Eulerian Path nor Circuit exists"
