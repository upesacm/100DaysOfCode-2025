from collections import deque

def bfs_traversal(vertices, edges, start=0):
    
    graph = [[] for _ in range(vertices)]
    for u, v in edges:
        graph[u].append(v)
        graph[v].append(u)  

    visited = [False] * vertices
    queue = deque([start])
    visited[start] = True

    bfs_order = []

    while queue:
        node = queue.popleft()
        bfs_order.append(node)

        for neighbor in graph[node]:
            if not visited[neighbor]:
                visited[neighbor] = True
                queue.append(neighbor)

    return bfs_order

print("BFS Example 1:", bfs_traversal(5, [[0,1],[0,2],[1,3],[2,4]]))  
print("BFS Example 2:", bfs_traversal(4, [[0,1],[1,2],[2,3]]))
