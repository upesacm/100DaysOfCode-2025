import heapq

def prim(n, adj):
    visited = [False] * n
    min_heap = [(0, 0)] 
    mst_cost = 0
    edges_used = 0

    while min_heap and edges_used < n:
        w, u = heapq.heappop(min_heap)
        if visited[u]:
            continue
        visited[u] = True
        mst_cost += w
        edges_used += 1
        for v, weight in adj[u]:
            if not visited[v]:
                heapq.heappush(min_heap, (weight, v))
    return mst_cost

adj = {
    0: [(1,2),(3,6)],
    1: [(0,2),(2,3),(3,8),(4,5)],
    2: [(1,3),(4,7)],
    3: [(0,6),(1,8),(4,9)],
    4: [(1,5),(2,7),(3,9)]
}
print("Prim MST cost:", prim(5, adj))  
