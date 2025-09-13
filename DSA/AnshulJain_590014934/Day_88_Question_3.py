from collections import deque

def isBipartite(V, edges):
    graph = [[] for _ in range(V)]
    for u, v in edges:
        graph[u].append(v)
        graph[v].append(u)
    
    color = [-1] * V  
    
    for start in range(V):
        if color[start] == -1:
            q = deque([start])
            color[start] = 0
            while q:
                node = q.popleft()
                for nei in graph[node]:
                    if color[nei] == -1:
                        color[nei] = 1 - color[node]
                        q.append(nei)
                    elif color[nei] == color[node]:
                        return False, []
    
    setA = [i for i in range(V) if color[i] == 0]
    setB = [i for i in range(V) if color[i] == 1]
    return True, (setA, setB)


V = int(input("Enter number of vertices: "))
E = int(input("Enter number of edges: "))

print("Enter the edges (u v) one per line:")
edges = [list(map(int, input().split())) for _ in range(E)]

possible, sets = isBipartite(V, edges)

if possible:
    print("Yes, the graph is bipartite.")
    print("Set A:", sets[0])
    print("Set B:", sets[1])
else:
    print("No, the graph is not bipartite.")
