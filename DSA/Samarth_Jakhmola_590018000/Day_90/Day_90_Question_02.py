def eulerian_path_circuit(vertices, edges):
    degree = [0] * vertices

    # Count degree of each vertex
    for u, v in edges:
        degree[u] += 1
        degree[v] += 1

    # Count odd degree vertices
    odd_count = sum(1 for d in degree if d % 2 == 1)

    if odd_count == 0:
        return "Eulerian Circuit Exists"
    elif odd_count == 2:
        return "Eulerian Path Exists"
    else:
        return "No Eulerian Path or Circuit"
    
try:
    vertices = int(input("Enter the number of vertices : "))
    edges_count = int(input("Enter the number of edges : "))
    edges = []

    print("Enter the vertices of each edge one by one, separated by spaces : ")
    for _ in range(edges_count):
        edges.append(list(map(int, input().split())))

    print(eulerian_path_circuit(vertices, edges))
except:
    print("Invalid input. Please try with a valid input.")
