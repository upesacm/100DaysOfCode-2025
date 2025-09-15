def eulerian_path_circuit(n, edges):
    degree = [0] * n
    for u,v in edges:
        degree[u] += 1
        degree[v] += 1
    odd = sum(d % 2 for d in degree)
    if odd == 0:
        return "Eulerian Circuit Exists"
    elif odd == 2:
        return "Eulerian Path Exists"
    else:
        return "No Eulerian Path or Circuit"

n = 4
edges = [[0,1],[1,2],[2,0],[0,3]]
print(eulerian_path_circuit(n, edges))

n = 3
edges = [[0,1],[1,2],[2,0]]
print(eulerian_path_circuit(n, edges))
