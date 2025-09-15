import heapq

def prim_mst(vertices, graph):
    visited = [False] * vertices
    min_heap = [(0, 0)]  # (weight, vertex) start from vertex 0
    mst_cost = 0
    edges_used = 0

    while min_heap and edges_used < vertices:
        weight, u = heapq.heappop(min_heap)

        if visited[u]:
            continue

        visited[u] = True
        mst_cost += weight
        edges_used += 1

        for v, w in graph[u]:
            if not visited[v]:
                heapq.heappush(min_heap, (w, v))

    return mst_cost

try:
    vertices = int(input("Enter the number of vertices : "))
    edges_count = int(input("Enter the number of edges : "))
    graph = [[] for _ in range(vertices)]
    print("Enter the vertices of the edge with their weight (source destination weight), separated by spaces : ")
    for _ in range(edges_count):
        u, v, w = map(int, input().split())
        graph[u].append((v, w))
        graph[v].append((u, w))  # because graph is undirected

    print(prim_mst(vertices, graph))
except:
    print("Invalid input. Please try with a valid input.") 
