# Your task: Implement BFS or DFS-based two-coloring to check if the graph can be properly colored with two colors without adjacent vertices sharing same color.
from collections import deque

def is_bipartite():
    num_vertices = int(input("Enter the number of vertices: "))
    edges = eval(input("Enter the edges as a list of lists, e.g., [[0,1],[1,2],[2,3],[3,0]]: "))

    adj = [[] for _ in range(num_vertices)]
    for u, v in edges:
        adj[u].append(v)
        adj[v].append(u)
    
    colors = [-1] * num_vertices
    is_bipartite = True

    for i in range(num_vertices):
        if colors[i] == -1:
            q = deque([(i, 0)])
            colors[i] = 0
            
            while q:
                node, color = q.popleft()
                
                for neighbor in adj[node]:
                    if colors[neighbor] == -1:
                        colors[neighbor] = 1 - color
                        q.append((neighbor, 1 - color))
                    elif colors[neighbor] == color:
                        is_bipartite = False
                        break
                if not is_bipartite:
                    break
        if not is_bipartite:
            break
            
    print("Output:", "Yes" if is_bipartite else "No")
    
is_bipartite()
