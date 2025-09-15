import heapq

def dijkstra_algorithm(vertices, edges, source):
    # Step 1 : Build adjacency list (u -> [(v, weight)])
    graph = [[] for _ in range(vertices)]
    for u, v, w in edges:
        graph[u].append((v, w))
        graph[v].append((u, w))   # undirected graph (remove this line if directed)

    # Step 2 : Initialize distances
    distance = [float("inf")] * vertices
    distance[source] = 0

    # Step 3 : Priority queue (min-heap)
    priority_queue = [(0, source)]  # (distance, node)

    while priority_queue:
        dist, node = heapq.heappop(priority_queue)

        # Skip if we already found a better distance
        if dist > distance[node]:
            continue

        # Step 4 : Relax edges
        for neighbour, weight in graph[node]:
            new_dist = dist + weight
            if new_dist < distance[neighbour]:
                distance[neighbour] = new_dist
                heapq.heappush(priority_queue, (new_dist, neighbour))
    
    return distance

try:
    vertices = int(input("Enter the number of vertices : "))
    edges_count = int(input("Enter the number of edges : "))
    edges = []
    print("Enter the vertices of each edge one by one followed by their weight, all of them separated by spaces : ")
    for _ in range(edges_count):
        edge = list(map(int, input().split()))
        edges.append(edge)

    source = int(input("Enter the source : "))
    print(dijkstra_algorithm(vertices, edges, source))
except:
    print("Invalid input. Please try with a valid input.")
