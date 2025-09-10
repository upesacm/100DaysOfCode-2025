def bellman_ford_algorithm(vertices, edges, source):
    # Step 1 : Initilaize distances
    distance = [float("inf")] * vertices
    distance[source] = 0

    # Step 2 : Relax edges V-1 times
    for _ in range(vertices - 1):
        for u, v, w in edges: 
            if distance[u] != float("inf") and distance[u] + w < distance[v]:
                distance[v] = distance[u] + w
    
    # Step 3 : Check for negative cycle
    for u, v, w in edges:
        if distance[u] != float("inf") and distance[u] + w < distance[v]:
            print("Graph contains a negative weight cycle.")
            return None
        
    return distance

try:
    vertices = int(input("Enter the number of vertices : "))
    edges_count = int(input("Enter the number of edges : "))
    edges = []
    print("Enter the vertices of each edge one by one, the two vertices being separated by spaces : ")
    for _ in range(edges_count):
        edge = list(map(int, input().split()))
        edges.append(edge)

    source = int(input("Enter the source : "))
    print(bellman_ford_algorithm(vertices, edges, source))
except:
    print("Invalid input. Please try with a valid input.")
