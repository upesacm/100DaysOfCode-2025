# Your task: Implement Prim's algorithm using priority queue and visited tracking to grow minimum spanning tree incrementally from starting vertex.
import heapq

def prims_algorithm():
    num_vertices = int(input("Enter the number of vertices: "))
    edges_str = input("Enter the edges as a list of tuples (u, v, weight): ")
    edges = eval(edges_str)

    adj = [[] for _ in range(num_vertices)]
    for u, v, weight in edges:
        adj[u].append((weight, v))
        adj[v].append((weight, u))

    min_heap = [(0, 0)]  # (weight, vertex)
    visited = [False] * num_vertices
    mst_cost = 0
    
    while min_heap:
        weight, u = heapq.heappop(min_heap)
        
        if visited[u]:
            continue
        
        visited[u] = True
        mst_cost += weight
        
        for neighbor_weight, v in adj[u]:
            if not visited[v]:
                heapq.heappush(min_heap, (neighbor_weight, v))
    
    print("Output:", mst_cost)

prims_algorithm()
