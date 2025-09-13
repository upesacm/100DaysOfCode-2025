def eulerian_type(n, edges):
    from collections import defaultdict

    degree = defaultdict(int)
    for u, v in edges:
        degree[u] += 1
        degree[v] += 1

    odd_count = sum(1 for d in degree.values() if d % 2 == 1)

    if odd_count == 0:
        return "Eulerian Circuit Exists"
    elif odd_count == 2:
        return "Eulerian Path Exists"
    else:
        return "No Eulerian Path or Circuit"
