import heapq

def prim_algorithm(vertices, adjacency_list):
    visited = [False] * vertices
    min_heap = [(0, 0)]
    total_weight = 0

    while min_heap:
        weight, node = heapq.heappop(min_heap)
        if visited[node]:
            continue
        visited[node] = True
        total_weight += weight

        for neighbor, edge_weight in adjacency_list[node]:
            if not visited[neighbor]:
                heapq.heappush(min_heap, (edge_weight, neighbor))

    return total_weight
