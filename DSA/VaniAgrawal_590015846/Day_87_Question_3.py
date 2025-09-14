# Your task: Implement Bellman-Ford algorithm using iterative edge relaxation to compute shortest distances while detecting negative cycles in weighted graphs.
def bellman_ford_algorithm():
    num_vertices = int(input("Enter the number of vertices: "))
    edges = eval(input("Enter the edges as a list of lists, e.g., [[0,1,-1],[0,2,4]]: "))
    source = int(input("Enter the source vertex: "))
    
    distances = [float('inf')] * num_vertices
    distances[source] = 0

    for _ in range(num_vertices - 1):
        for u, v, weight in edges:
            if distances[u] != float('inf') and distances[u] + weight < distances[v]:
                distances[v] = distances[u] + weight

    # Check for negative cycles
    has_negative_cycle = False
    for u, v, weight in edges:
        if distances[u] != float('inf') and distances[u] + weight < distances[v]:
            has_negative_cycle = True
            break
    
    if has_negative_cycle:
        print("Graph contains a negative weight cycle")
    else:
        print("Output:", distances)

bellman_ford_algorithm()
