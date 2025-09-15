import heapq

def prim(vertices, edges):
    graph = [[] for _ in range(vertices)]
    for u, v, w in edges:
        graph[u].append((w, v))
        graph[v].append((w, u))
    visited = [False]*vertices
    pq = [(0, 0)]
    mst_cost = 0
    while pq:
        w, u = heapq.heappop(pq)
        if visited[u]:
            continue
        visited[u] = True
        mst_cost += w
        for nw, v in graph[u]:
            if not visited[v]:
                heapq.heappush(pq, (nw, v))
    return mst_cost

print(prim(5, [[0,1,2],[0,3,6],[1,2,3],[1,3,8],[1,4,5],[2,4,7],[3,4,9]]))
print(prim(4, [[0,1,1],[0,2,2],[1,3,3],[2,3,4]]))
